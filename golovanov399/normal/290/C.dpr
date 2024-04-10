{$APPTYPE CONSOLE}

var
 n, s, i, x, t, y: integer;
 
begin
 readln(n);
 s := 0;
 t := 0;
 y := 0;
 for i := 1 to n do
 begin
  read(x);
  s := s + x;
  if (t * i <= s * y) then
  begin
   t := s;
   y := i;
  end;
 end;
 writeln((t / y):0:12);
end.