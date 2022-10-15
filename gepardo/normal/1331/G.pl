sub __enlist__ {
    return ($_[0]..$_[1]);
}

sub getline {
    return <>;
}

#line 2
;for $next (__enlist__ ( 1, 11)) { $var = getline (*STDIN );
chomp ($var );
push (@seq, $var)}
;
for $next (__enlist__ ( 1, 11)) { $var = pop (@seq );
 $aresult = sqrt ( abs ( $var));
 $bresult =  ( ($var ** 3) * 5);
 $result =  ($aresult + $bresult);
if ( (400 >= $result)) {printf (STDOUT 'f(%d) = %.2f', $var, $result);
print (STDOUT "\n")}
;
if ( (400 < $result)) {printf (STDOUT 'f(%d) = MAGNA NIMIS!', $var);
print (STDOUT "\n")}
}