var
  a,b,c:array[1..100000]of longint;
  n,i:longint;
begin
  readln(n);
  for i:=1 to n do begin
    readln(a[i],b[i]);
    inc(c[a[i]]);
  end;
  for i:=1 to n do begin
    writeln(n-1+c[b[i]],' ',n-1-c[b[i]]);
  end;
end.