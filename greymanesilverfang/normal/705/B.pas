program Project705B;
var n, w, i, x: integer;
procedure switch;
begin
  if w = 1 then w := 2 else w := 1;
end;
begin
  w := 2;
  readln(n);
  for i := 1 to n do
  begin
    read(x);
    if x mod 2 = 0 then switch;
    writeln(w);
  end;
end.