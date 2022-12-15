my $n = <>;
chomp $n;
my $ans = (length($n)-1)*9;
for (0..9) {
    my $cnt = () = $n =~/$_/g;
    $ans += $_ * $cnt;
}
for (1..(length($n)-1)) {
    my $str = 9x$_;
    if ($n =~ m/$str$/) {
        $ans -= 9;
    }
}
print $ans."\n";