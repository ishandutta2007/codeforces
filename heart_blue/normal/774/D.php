<?php
fscanf(STDIN,"%d %d %d\n",$n, $l, $r);
$l--;
$r--;
$a=explode(" ",trim(fgets(STDIN)));
$b=explode(" ",trim(fgets(STDIN)));


$flag = 1;
for($x = 0; $x < $l; $x++) {
    if($a[$x] != $b[$x])
        $flag = 0;
}
for($x = $r+1; $x < $n; $x++) {
    if($a[$x] != $b[$x])
        $flag = 0;
}
sort($a);
sort($b);
for($x = 0; $x < $n; $x++) {
    if($a[$x] != $b[$x])
        $flag = 0;
}
echo($flag==0)?'LIE':'TRUTH';