var n: integer;
begin
readln(n);
if n mod 4 = 2 then writeln(1, ' B')
else writeln((4-(n-1) mod 4) mod 4, ' A');
end.