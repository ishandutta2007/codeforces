var
  a:array[1..1000000]of longint;
  n,m,i,x:longint;
begin
  readln(n);
  for i:=1 to n do begin
    read(x);
    while x>0 do begin
      inc(m);dec(x);a[m]:=i;
    end;
  end;
  readln(m);
  for i:=1 to m do begin
    read(x);writeln(a[x]);
  end;
end.