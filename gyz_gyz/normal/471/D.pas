var
  a,b,p:array[1..200000]of longint;
  n,m,i,x,y,ans:longint;
begin
  readln(n,m);
  if m=1 then begin
    writeln(n);halt;
  end;
  dec(n);read(x);
  for i:=1 to n do begin
    read(y);a[i]:=y-x;x:=y;
  end;
  dec(m);read(x);
  for i:=1 to m do begin
    read(y);b[i]:=y-x;x:=y;
  end;
  for i:=2 to m do begin
    x:=p[i-1];
    while (x<>0)and(b[x+1]<>b[i]) do x:=p[x];
    if b[x+1]=b[i] then p[i]:=x+1;
  end;
  x:=0;
  for i:=1 to n do begin
    while (x<>0)and(a[i]<>b[x+1]) do x:=p[x];
    if a[i]=b[x+1] then inc(x);
    if x=m then begin
      inc(ans);x:=p[x];
    end;
  end;
  writeln(ans);
end.