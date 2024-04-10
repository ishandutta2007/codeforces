var i,n, k1,k2: longint;
    a: array [1..300000] of longint;

begin
  readln (n);
  for i:=1 to n do read (a[i]);
  
  for i:=n downto 1 do if a[i]<>a[1] then
  begin
    k1:=i;
    break;
  end;
  
  for i:=1 to n do if a[i]<>a[n] then
  begin
    k2:=i;
    break;
  end;
  
writeln (max (n-k2,k1-1));
end.