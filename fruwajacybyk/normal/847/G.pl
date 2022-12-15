$n = <>;
chomp;
for ($i = 0; $i < $n; $i++) {
	$code = <>;
	chomp;
	for ($j = 0; $j < 7; $j++) {
		if (substr($code, $j, 1) eq "1") {
			$list[$j]++;
		}
	}
}
$ans = 0;
for ($j = 0; $j < 7; $j++) {
	if ($list[$j] > $ans) {
		$ans = $list[$j];
	}
}
print "$ans\n";