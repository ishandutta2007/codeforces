const max:int64=1000000007;
var
  a,b:array[0..1000,0..1000]of int64;
  n,k,d,i,j,l:longint;
  ans:int64;
begin
  readln(n,k,d);
  a[0,0]:=1;
  for i:=0 to n-1 do
    for j:=0 to n-1 do
      for l:=1 to k do
        a[i+1,j+l]:=(a[i+1,j+l]+a[i,j]) mod max;
  b[0,0]:=1;
  for i:=0 to n-1 do
    for j:=0 to n-1 do
      for l:=1 to d-1 do
        b[i+1,j+l]:=(b[i+1,j+l]+b[i,j]) mod max;
  for i:=1 to n do
    ans:=(ans+a[i,n]) mod max;
  for i:=1 to n do
    ans:=(ans-b[i,n]+max) mod max;
  writeln(ans);
end.