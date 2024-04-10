var
  a,b:array[1..2000,1..2000]of int64;
  p,c,f:array[1..2000]of int64;
  n,x,xx:int64;
  i,j:longint;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do begin
      read(b[i,j]);
      if (i<>j)and(b[i,j]=0)or
      (i=j)and(b[i,j]>0)or
      (i>j)and(b[i,j]<>b[j,i]) then begin
        writeln('NO');halt;
      end;
    end;
  fillchar(p,sizeof(p),$7f);
  p[1]:=0;
  while true do begin
    xx:=maxlongint;x:=0;
    for i:=1 to n do
      if (c[i]=0)and(p[i]<xx) then begin
        xx:=p[i];x:=i;
      end;
    if x=0 then break;
    if f[x]<>0 then
      for i:=1 to n do
        if c[i]=1 then begin
          a[x,i]:=b[x,f[x]]+a[f[x],i];
          a[i,x]:=b[f[x],x]+a[i,f[x]];
        end;
    c[x]:=1;
    for i:=1 to n do
      if (c[i]=0)and(b[x,i]<p[i]) then begin
        p[i]:=b[x,i];f[i]:=x;
      end;
  end;
  for i:=1 to n do
    for j:=1 to n do
      if a[i,j]<>b[i,j] then begin
        writeln('NO');halt;
      end;
  writeln('YES');
end.