var
  a,b:array[1..5,1..1000]of longint;
  f:array[1..1000]of longint;
  n,k,i,j,l,t,e:longint;
begin
  readln(n,k);
  for i:=1 to k do
    for j:=1 to n do begin
      read(a[i,j]);b[i,a[i,j]]:=j;
    end;
  for i:=2 to n do begin
    for j:=1 to i-1 do begin
      e:=0;
      for l:=2 to k do
        if b[l,a[1,j]]>b[l,a[1,i]] then e:=1;
      if e=0 then
        if f[j]+1>f[i] then f[i]:=f[j]+1;
    end;
    if f[i]>t then t:=f[i];
  end;
  writeln(t+1);
end.