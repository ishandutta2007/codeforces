var
  n,m:longint;
function gcd(x,y:longint):longint;
begin
  if y=0 then exit(x) else exit(gcd(y,x mod y));
end;
begin
  readln(n,m);
  write(gcd(n-1,m-1)+1);
end.