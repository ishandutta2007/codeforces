var n,m,a,b,ans:longint;
begin
  readln(n,m,a,b);ans:=a*n;
  if ((n-1) div m+1)*b<ans then ans:=((n-1) div m+1)*b;
  if a*(n mod m)+b*(n div m)<ans then ans:=a*(n mod m)+b*(n div m);
  writeln(ans);
end.