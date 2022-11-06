var
  a,b:array[1..100000]of int64;
  n,i:longint;
  p,ans:int64;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=n downto 1 do begin
    inc(p,a[i]);
    if p>a[i] then begin
      dec(p,a[i]*2);b[i]:=1;
    end;
  end;
  if p<0 then
    for i:=1 to n do b[i]:=1-b[i];
  for i:=1 to n do
    if b[i]=0 then write('+') else write('-');
  writeln;
end.