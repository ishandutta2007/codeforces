$n = <>;
@v = split(/ /, <>);

$ans = "Second";
foreach (@v) {
	if ($_ % 2 == 1) {
		$ans = "First";
	}
}

print "$ans\n";