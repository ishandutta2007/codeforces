var
  a:array[1..5,1..5]of int64;
  b,c:array[1..5]of longint;
  i,j:longint;
  ans:int64;
procedure pd;
var
  i,j:longint;
  s:int64;
begin
  s:=0;
  for i:=0 to 5 do
    for j:=1 to (5-i) div 2 do
      inc(s,a[b[i+j*2-1],b[i+j*2]]+a[b[i+j*2],b[i+j*2-1]]);
  if s>ans then ans:=s;
end;
procedure f(x:longint);
var i:longint;
begin
  if x=6 then pd;
  for i:=1 to 5 do
    if c[i]=0 then begin
      c[i]:=1;b[x]:=i;f(x+1);b[x]:=0;c[i]:=0;
    end;
end;
begin
  for i:=1 to 5 do
    for j:=1 to 5 do
      read(a[i,j]);
  f(1);
  writeln(ans);
end.