var n,i,z,z1,ed,ed1: longint;
    a: array [1..200000] of longint;

begin
  readln (n);
  for i:=1 to n do read (a[i]);
  for i:=1 to n do
  begin
    if a[i]=0 then z:=z+1;
    if a[i]=1 then ed:=ed+1;
  end;
  i:=1; 
  while (z>z1) and (ed>ed1) do
  begin
    if a[i]=0 then z1:=z1+1;
    if a[i]=1 then ed1:=ed1+1;
    i:=i+1;
  end;
  writeln (i-1);
end.