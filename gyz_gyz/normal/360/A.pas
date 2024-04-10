var
  a,b,c,d,p,q:array[1..5000]of int64;
  n,m,i,j:longint;
  x:int64;
begin
  readln(n,m);
  for i:=1 to m do readln(a[i],b[i],c[i],d[i]);
  fillchar(p,sizeof(p),$7f);
  for i:=1 to m do
    if a[i]=2 then begin
      for j:=b[i] to c[i] do
        if p[j]+q[j]>d[i] then
          p[j]:=d[i]-q[j];
    end else begin
      for j:=b[i] to c[i] do inc(q[j],d[i]);
    end;
  for i:=1 to n do q[i]:=p[i];
  for i:=1 to m do
    if a[i]=2 then begin
      x:=-1000000000000000000;
      for j:=b[i] to c[i] do
        if q[j]>x then x:=q[j];
      if x<>d[i] then begin
        writeln('NO');halt;
      end;
    end else begin
      for j:=b[i] to c[i] do inc(q[j],d[i]);
    end;
  for i:=1 to n do
    if p[i]<-1000000000 then begin
      writeln('NO');halt;
    end;
  writeln('YES');
  for i:=1 to n do
    if p[i]<=1000000000 then write(p[i],' ') else write('1000000000 ');
  writeln;
end.