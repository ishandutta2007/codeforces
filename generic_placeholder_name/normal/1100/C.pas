uses math;
var n: integer;
        r, r_out, cosx: real;
begin
readln(n, r);
cosx:=cos(pi*(n-2)/n/2);
r_out:=r*cosx/(1-cosx);
writeln(r_out:0:7);
end.