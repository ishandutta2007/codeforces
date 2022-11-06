const mx:int64=1000000007;
var
  a:array[0..3000,0..3000]of int64;
  b:array[1..3000]of longint;
  n,h,i,j,x:longint;
begin
  readln(n,h);
  for i:=1 to n do read(b[i]);
  a[0,0]:=1;
  for i:=1 to n do begin
    x:=h-b[i];
    a[i,x]:=(a[i,x]+a[i-1,x-1]) mod mx;
    a[i,x]:=(a[i,x]+(a[i-1,x]+a[i-1,x+1])*(x+1)) mod mx;
  end;
  if a[n,1]>a[n,0] then writeln(a[n,1]) else writeln(a[n,0]);
end.