<?
$n=fgets(STDIN);
$b = explode(' ',trim(fgets(STDIN)));
$c = -1;
$d = 0;
$cnt = 0;
$flag = 1;
for ($i = 0; $i < $n; $i++) {
    $a = $b[$i];
    //echo $a;
    if($i == 0)
    {
        $c = $a;
        $d = 1;
    }
    else
    {
        if($a == $c) $d++;
        else
        {
           //echo $a,' ', $c, '\n';
            if($cnt == 0) $cnt = $d;
            if($cnt != $d) $flag = 0;
            $d = 1;
            $c = $a;
        }
    }
}
//echo $cnt;
//echo $d;
if($cnt == 0) $cnt = $d;
if($cnt != $d) $flag = 0;
if($flag) echo "YES";
else echo "NO";
?>