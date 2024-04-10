var
    p, min, a, b, i: longint;
begin
    read(min);
   for i := 1 to 3 do begin
   read(p);
   if min > p then min := p;
   end;
  read(a, b);
 if min > b then min := b+1;
if min < a then
write(0)
else
write(min - a);
end.