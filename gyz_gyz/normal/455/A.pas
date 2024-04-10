var
  a,b:array[0..200000]of int64;
  n,i,x:longint;
begin
  readln(n);
  for i:=1 to n do begin
    read(x);inc(b[x],x);
  end;
  for i:=2 to 200000 do
    if a[i-2]+b[i-1]<a[i-1] then a[i]:=a[i-1] else a[i]:=a[i-2]+b[i-1];
  writeln(a[200000]);
end.