const mx=1000000;
var
  a,b:array[0..2000000]of longint;
  n,i,j,ans:longint;
begin
  readln(n);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do a[b[i]]:=b[i];
  for i:=1 to 2000000 do
    if a[i]=0 then a[i]:=a[i-1];
  for i:=1 to 2000000 do
    if a[i]=i then
      for j:=2 to mx div i+1 do
        if (j-1=a[j*i-1] div i)and(a[j*i-1] mod i>ans) then
          ans:=a[j*i-1] mod i;
  writeln(ans);
end.