use uo;
use os;
use cfgfile;

/*
 * Focus_GetSettingsCfgFile(engine_name)
 *
 * Purpose
 * Reads in :focus:config/settings.cfg
 *
 * Parameters
 *
 * Return value
 * A config file reference.
 *
 */
function Focus_GetSettingsCfgFile()
	UnloadConfigFile(":focus:config/settings");
	var cfg := ReadConfigFile(":focus:config/settings");

	if ( cfg.errortext )
		SysLog("Error::Focus_GetSettingsCfgFile() - Unable to open [:focus:config/settings.cfg] ->"+cfg.errortext);
	endif

	return cfg;
endfunction

/*
 * Focus_GetSettingsCfgElem(elem_name, cfg_file)
 *
 * Purpose
 * Retrieves an elem from a config file.
 *
 * Parameters
 * elem_name:	A string matching the elem name to be retrieved.
 * cfg_file:	Optional parameter - reference to a config already read in by Focus_GetSettingsCfgFile()
 *
 * Return value
 * A config file elem reference.
 *
 */
function Focus_GetSettingsCfgElem(elem_name, byref cfg_file:=0)
	if ( !cfg_file )
		cfg_file := Focus_GetSettingsCfgFile();
	endif

	var elem := cfg_file[elem_name];

	if ( elem.errortext )
		SysLog("Error::Focus_GetSettingsCfgElem() - Unable to find elem ["+elem_name+"] ->"+elem.errortext);
	endif

	return elem;
endfunction

