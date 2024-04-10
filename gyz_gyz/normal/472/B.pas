var
  a:array[1..2000]of longint;
  n,k,i,j,x,ans:longint;
begin
  readln(n,k);
  for i:=1 to n do begin
    read(x);inc(a[x]);
  end;
  x:=k;
  for i:=2000 downto 1 do begin
    inc(x,a[i]);
    while x>k do begin
      dec(x,k);inc(ans,2*(i-1));
    end;
  end;
  writeln(ans);
end.