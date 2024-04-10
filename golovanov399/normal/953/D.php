<?php

$n = 6;
for ($i = 0; $i < $n; ++$i) {
    $s[$i] = fgets(STDIN);
}

$x = 0;
$y = 0;
$z = 0;
for ($i = 0; $i < 6; ++$i) {
    for ($j = 0; $j < 8; ++$j) {
        if ($s[$i][$j] != '.') {
            continue;
        }
        $k = 4 - intdiv($i, 2) - abs(1 - intdiv($j, 3));
        if ($k > $z) {
            $z = $k;
            $x = $i;
            $y = $j;
        }
    }
}

$s[$x][$y] = 'P';
for ($i = 0; $i < $n; ++$i) {
    echo $s[$i];
}

?>