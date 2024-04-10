$count = 1;
while ($count <= 11) { 
$var = <STDIN>;
chomp ($var );
push (@seq, $var);
$count++;}
;
$count = 1;
while ($count <= 11) {
 $var = pop (@seq );
 $aresult = sqrt ( abs ( $var));
 $bresult =  ( ($var ** 3) * 5);
 $result =  ($aresult + $bresult);
if ( (400 >= $result)) {printf (STDOUT 'f(%d) = %.2f', $var, $result);
print (STDOUT "\n")}
;
if ( (400 < $result)) {printf (STDOUT 'f(%d) = MAGNA NIMIS!', $var);
print (STDOUT "\n");
}$count++;
}