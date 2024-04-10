{$APPTYPE CONSOLE}

var
 n, i, k: integer;
 r: extended;
 x, y, z, t: extended;

begin
 readln(n, k);
 r:=0;
 readln(x, y);
 for i:=1 to n-1 do
 begin
  readln(z, t);
  r:=r+sqrt(sqr(z-x) + sqr(t-y));
  x:=z;
  y:=t;
 end;
 writeln((r*k/50):0:6);
end.