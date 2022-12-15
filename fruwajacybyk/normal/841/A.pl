($n, $k) = split(/ /,<>);
chomp ($ball = <>);

$ans = "YES";

for ($i = 0; $i < $n; ++$i) {
	$let = substr ($ball, $i, 1);
	$count{$let}++;
	if ($count{$let} > $k) {
		$ans = "NO";
	}
}


print "$ans\n";