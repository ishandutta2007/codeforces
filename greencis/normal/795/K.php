<?php
 
$fl =STDIN;
fscanf($fl,"%s\n",$a);
fscanf($fl,"%s\n",$a);
$b="";
$n=strlen($a);
$prv='=';
$cnt=0;
for($i=0;$i<$n;++$i)
{
	if ($a[$i]==$prv)
		++$cnt;
	else {
		if ($prv=='a'||$prv=='e'||$prv=='i'||$prv=='o'||$prv=='u'||$prv=='y')
		if ($prv != 'e' && $prv != 'o' ||$cnt != 2)
			$cnt = 1;
		if ($prv!='=')
		while ($cnt-- > 0) {
			$b .= $prv;
		}
		$prv = $a[$i];
		$cnt = 1;
	}
	
		
}
if ($prv=='a'||$prv=='e'||$prv=='i'||$prv=='o'||$prv=='u'||$prv=='y')
if ($prv != 'e' && $prv != 'o' || $cnt != 2)
			$cnt = 1;
if ($prv!='=')
while ($cnt-- > 0) {
			$b .= $prv;
		}
 
printf("%s\n",$b);
?>