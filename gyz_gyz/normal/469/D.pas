var
  a,w,b,tt:array[1..100000]of longint;
  n,p,q,i:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;x:=a[(l+r) shr 1];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then begin
      y:=a[i];a[i]:=a[j];a[j]:=y;
      y:=w[i];w[i]:=w[j];w[j]:=y;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
function f(x:longint):longint;
var l,r,mid:longint;
begin
  l:=1;r:=n;mid:=(l+r) shr 1;
  while l<=r do begin
    if a[mid]=x then
      if b[mid]=0 then exit(mid) else exit(0);
    if a[mid]<x then l:=mid+1 else r:=mid-1;
    mid:=(l+r) shr 1;
  end;
  exit(0);
end;
procedure s(i:longint);
var x,y:longint;
begin
  x:=f(p-a[i]);y:=f(q-a[i]);
  if (x=0)and(y=0) then begin
    writeln('NO');halt;
  end;
  if x=0 then begin
    b[i]:=2;b[y]:=2;
    x:=f(p-a[y]);
    if x>0 then s(x);
    exit;
  end;
  if y=0 then begin
    b[i]:=1;b[x]:=1;
    y:=f(q-a[x]);
    if y>0 then s(y);
    exit;
  end;
end;
begin
  readln(n,p,q);
  for i:=1 to n do begin
    read(a[i]);w[i]:=i;
  end;
  sort(1,n);
  for i:=1 to n do
    if b[i]=0 then s(i);
  writeln('YES');
  for i:=1 to n do
    if b[i]=0 then b[i]:=1;
  for i:=1 to n do tt[w[i]]:=i;
  for i:=1 to n do write(b[tt[i]]-1,' ');
  writeln;
end.