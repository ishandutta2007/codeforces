<?php
$n = intval(fgets(STDIN));
$s = fgets(STDIN);

$res = "";
for ($i = 0; $i < $n; ++$i) {
    if ($i == $n - 1) {
        $res .= $s[$i];
    } else if ($s[$i] != $s[$i + 1] || ($s[$i] != 'a' && $s[$i] != 'o' && $s[$i] != 'u' && $s[$i] != 'e' && $s[$i] != 'i' && $s[$i] != 'y')) {
        $res .= $s[$i];
    } else {
        $j = $i;
        while ($j < $n && $s[$j] == $s[$i]) {
            ++$j;
        }
        if ($j == $i + 2 && ($s[$i] == 'e' || $s[$i] == 'o')) {
            $res .= $s[$i];
            $res .= $s[$i];
        } else {
            $res .= $s[$i];
        }
        $i = $j - 1;
    }
}

echo $res;
?>