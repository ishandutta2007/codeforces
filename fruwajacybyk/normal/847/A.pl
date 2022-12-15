$n = <>;
chomp;
for ($i = 0; $i < $n; $i++) {
	($a, $b)  = split(' ', <>);
	$prev[$i+1] = $a;
	$nxt[$i+1] = $b;
	if ($prev[$i + 1] == 0) {
		$start = $i + 1;
	}
}



$ok = 1;
while ($ok) {
	($a, $b) = (0, $start);
	$len = 0;
	while ($b != 0) {
		($a, $b) = ($b, $nxt[$b]);
		$len++;
	}
	if ($len == $n) {
		$ok = 0;
	}
	if ($ok) {
		$ok2 = 1;
		for ($i = 1; $i <= $n; $i++) {
			if ($ok2 && $i != $start && $prev[$i] == 0) {
				$nxt[$a] = $i;
				$prev[$i] = $a;
				$ok2 = 0;
			}
		}
	}
}

for ($i = 1; $i <= $n; $i++) {
	print "$prev[$i] $nxt[$i]\n";
}