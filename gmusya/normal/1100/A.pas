var sum,n,k,i,j,zn,max:longint;
    a,b:array [1..1000] of longint;

begin
  readln (n,k);
  for i:=1 to n do read (a[i]);
  for i:=1 to n do sum:=sum+a[i];
  zn:=n div k;
  for i:=1 to k do
  begin
    for j:=0 to zn do b[i]:=b[i]+a[i+k*j];
    b[i]:=sum-b[i];
    if b[i]<0 then b[i]:=-1*b[i];
  end;
  max:=b[1];
  for i:=1 to n do if b[i]>max then max:=b[i];
  writeln (max);
end.