var n,b,k,i: int64;
begin
  readln (b);
  while n*n<b do
  begin
    n:=n+1;
  end;
  for i:=1 to n do if (b mod i = 0) and (b div i>i) then k:=k+2 else if (b mod i = 0) and (b div i = i) then k:=k+1;
  writeln (k);
end.