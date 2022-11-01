var a,b,c: longint;
begin
  readln (a,b,c);
  if c+b<=a then writeln (a-c-b+1) else
  if a+b<=c then writeln (c-a-b+1) else
  if a+c<=b then writeln (b-a-c+1) else
  writeln ('0');
end.