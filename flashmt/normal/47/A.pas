var n,i:longint;
begin
     read(n);
     for i:=1 to n do
         if i*(i+1) div 2=n then
         begin
              writeln('YES'); halt;
         end;
     writeln('NO');
end.