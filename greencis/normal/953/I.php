<?php

$fl = STDIN;
fscanf($fl, "%d", $n);
$arr = array();
for ($i = 0; $i < $n; ++$i) {
    fscanf($fl, "%d%c%d", $h, $zzz, $m);
    $arr = array_merge($arr, array($m + $h * 60));
}

sort($arr);
$arr = array_merge($arr, array($arr[0] + 1440));

$mx = 0;
for ($i = 0; $i < $n; ++$i) {
    $mx = max($mx, $arr[$i + 1] - 1 - $arr[$i]);
}

printf("%d%d:%d%d", $mx/60/10, $mx/60%10, $mx%60/10, $mx%60%10);

?>