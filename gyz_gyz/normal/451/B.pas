var
  a,b:array[1..100000]of longint;
  n,i,l,r:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;x:=a[(l+r) shr 1];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then begin
      y:=a[i];a[i]:=a[j];a[j]:=y;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  b:=a;sort(1,n);
  l:=1;r:=n;
  while (a[l]=b[l])and(l<n) do inc(l);
  while (a[r]=b[r])and(r>1) do dec(r);
  if l>=r then begin
    writeln('yes');writeln('1 1');exit;
  end;
  for i:=0 to r-l do
    if a[l+i]<>b[r-i] then begin
      writeln('no');exit;
    end;
  writeln('yes');writeln(l,' ',r);
end.