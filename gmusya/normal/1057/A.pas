var n,i,k: longint;
    a,b:array [1..200000] of longint;
begin
  readln (n);
  for i:=2 to n do read (a[i]);
  a[1]:=0;
  k:=1;
  i:=n;
  while (a[i]>0) do
  begin
    b[k]:=i;
    k:=k+1;
    i:=a[i];
  end;
  k:=k-1;
  write ('1 ');
  for i:=k downto 1 do write (b[i], ' ');
end.