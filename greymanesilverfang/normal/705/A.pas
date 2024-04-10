program Project705A;
var n, i: integer;
begin
  read(n);
  for i := 1 to n do
      begin
      write('I ');
      if i mod 2 = 1 then write('hate ') else write('love ');
      if i = n then write('it') else write('that ');
      end;
end.