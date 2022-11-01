var n,i,m,z: longint;
    a: array [1..10000] of longint;
begin
  readln (n);
  for i:=1 to n do read (a[i]);
  for i:=1 to n do
  begin
    m:=max(a[i],m);
    if i>=m then 
    begin
      z:=z+1;
      m:=0;
    end;
  end;
  writeln (z);
end.