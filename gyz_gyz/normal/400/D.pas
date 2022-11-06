var
  a:array[1..500,1..500]of longint;
  s:array[1..500]of longint;
  c,f:array[1..100000]of longint;
  n,m,w,i,j,k,x,y,z:longint;
function gf(x:longint):longint;
begin
  if f[x]=x then exit(x);
  f[x]:=gf(f[x]);exit(f[x]);
end;
begin
  readln(n,m,w);
  for i:=1 to n do f[i]:=i;
  for i:=1 to w do read(s[i]);
  j:=0;k:=0;
  for i:=1 to n do begin
    if i>k then begin
      inc(j);inc(k,s[j]);
    end;
    c[i]:=j;
  end;
  for i:=1 to w do
    for j:=1 to w do
      a[i,j]:=1000000000;
  for i:=1 to m do begin
    readln(x,y,z);
    if a[c[x],c[y]]>z then begin
      a[c[x],c[y]]:=z;
      a[c[y],c[x]]:=z;
    end;
    if z=0 then begin
      x:=gf(x);y:=gf(y);f[x]:=y;
    end;
  end;
  i:=0;j:=0;k:=0;
  while i<n do begin
    inc(i);
    while i>k do begin
      inc(i);inc(j);inc(k,s[j]);
      if i>n then break;
    end;
    if i>n then break;
    if gf(i)<>gf(i-1) then begin
      writeln('No');halt;
    end;
  end;
  writeln('Yes');
  for i:=1 to w do a[i,i]:=0;
  for k:=1 to w do
    for i:=1 to w do
      if i<>k then
        for j:=1 to w do
          if (k<>j)and(i<>j)and
          (a[i,k]+a[k,j]<a[i,j]) then begin
            a[i,j]:=a[i,k]+a[k,j];
          end;
  for i:=1 to w do begin
    for j:=1 to w do
      if a[i,j]<1000000000 then write(a[i,j],' ')
      else write('-1 ');
    writeln;
  end;
end.