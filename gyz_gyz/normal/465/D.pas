const
  u:array[1..6,1..3]of longint=
  ((1,2,3),(1,3,2),(2,1,3),(2,3,1),(3,1,2),(3,2,1));
var
  a,b:array[1..8,1..3]of int64;
  dr:array[1..8,1..8]of int64;
  i,j:longint;
function ds(x,y:longint):int64;
begin
  exit((a[x,1]-a[y,1])*(a[x,1]-a[y,1])+
  (a[x,2]-a[y,2])*(a[x,2]-a[y,2])+
  (a[x,3]-a[y,3])*(a[x,3]-a[y,3]));
end;
procedure p;
var
  i,j,s,g:longint;
  d,r:int64;
begin
  d:=maxlongint;d:=d*d;r:=d;
  for i:=1 to 8 do
    for j:=1 to 8 do begin
      dr[i,j]:=ds(i,j);
      if (i<>j)and(dr[i,j]<d) then d:=dr[i,j];
    end;
  for i:=1 to 8 do
    for j:=1 to 8 do
      if (i<>j)and(dr[i,j]>d)
      and(dr[i,j]<r) then r:=dr[i,j];
  for i:=1 to 6 do begin
    s:=0;g:=0;
    for j:=1 to 8 do begin
      if dr[i,j]=d then inc(s);
      if dr[i,j]=r then inc(g);
    end;
    if (s<>3)or(g<>3) then exit;
  end;
  writeln('YES');
  for i:=1 to 8 do begin
    for j:=1 to 3 do write(a[i,j],' ');
    writeln;
  end;
  halt;
end;
procedure f(x:longint);
var i,j:longint;
begin
  if x=9 then begin
    p;exit;
  end;
  for i:=1 to 6 do begin
    for j:=1 to 3 do
      a[x,j]:=b[x,u[i,j]];
    f(x+1);
  end;
end;
begin
  for i:=1 to 8 do
    for j:=1 to 3 do read(b[i,j]);
  a[1,1]:=b[1,1];a[1,2]:=b[1,2];a[1,3]:=b[1,3];
  f(2);writeln('NO');
end.