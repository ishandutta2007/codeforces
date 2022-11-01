var i,t: int64;
    s,a,b,c: array [1..100] of int64;

begin
  readln (t);
  for i:=1 to t do read (s[i], a[i], b[i], c[i]);
  for i:=1 to t do writeln ((s[i] div (a[i]*c[i])*(a[i]+b[i])) + ((s[i] - s[i] div (a[i]*c[i])*a[i]*c[i])) div c[i]);
end.