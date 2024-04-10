var n, i: longint;

begin
  readln(n);
  if n = 2 then begin writeln(-1); exit end;
  writeln(6); writeln(10);
  for i := 1 to n - 2 do writeln(15 * i); 
end.