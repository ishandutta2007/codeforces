$n = <>;
chomp;
@list = split(' ',<>);
$x = 0;
for ($i = 0; $i + 2 < $n; $i++) {
	if ($list[$i] + $list[$i+2] != 2*$list[$i + 1]) {
		$x = 1;
	}
}


if ($x == 1) {
	$ans = $list[$n-1];
} else {
	$ans = 2*$list[$n-1]-$list[$n-2];
}
print "$ans\n";