var
 n, i, x: integer;
 
begin
 reset(input,'input.txt');
 rewrite(output,'output.txt');
 readln(n);
 for i := 1 to n do
 begin
  readln(x);
  if odd(x) then writeln(0) else writeln(1);
 end;
end.