var
  a,b:array[1..2000]of longint;
  n,i,x:longint;
procedure swap(x,y:longint);
var z:longint;
begin
  z:=a[x];a[x]:=a[y];a[y]:=z;
  z:=b[x];b[x]:=b[y];b[y]:=z;
end;
procedure sort(l,r:longint);
var i,j,x:longint;
begin
  i:=l;j:=r;x:=a[(l+r) shr 1];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then begin
      swap(i,j);inc(i);dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do b[i]:=i;
  sort(1,n);
  for i:=1 to n-1 do
    if a[i]=a[i+1] then inc(x);
  if x<=1 then begin
    writeln('NO');halt;
  end;
  writeln('YES');
  for i:=1 to n do write(b[i],' ');
  writeln;
  for i:=1 to n do
    if a[i]=a[i+1] then begin
      swap(i,i+1);break;
    end;
  for i:=1 to n do write(b[i],' ');
  writeln;
  for i:=n downto 1 do
    if a[i]=a[i-1] then begin
      swap(i,i-1);break;
    end;
  for i:=1 to n do write(b[i],' ');
  writeln;
end.