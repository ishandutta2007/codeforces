var
  a:array[1..5000]of longint;
  b,c:array[0..100]of longint;
  n,m,i,j,x1,x2,ans:longint;
begin
  readln(n,m);
  for i:=1 to n do begin
    read(a[i]);inc(b[a[i]]);inc(c[a[i]]);
  end;
  ans:=0;
  for i:=1 to m do
    if b[i]>ans then ans:=b[i];
  ans:=ans*2;
  if ans>n then writeln(2*n-ans) else writeln(n);
  for i:=1 to n do begin
    x1:=0;x2:=0;
    for j:=1 to m do
      if b[x1]<=b[j] then x1:=j;
    for j:=1 to m do
      if (j<>x1)and(c[x2]<c[j]) then x2:=j;
    if x2=0 then x2:=x1;dec(b[x1]);dec(c[x2]);
    writeln(x1,' ',x2);
  end;
end.