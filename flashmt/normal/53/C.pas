var n,i,l,r:longint;
begin
     read(n);
     l:=1; r:=n;
     for i:=1 to n do
         if odd(i) then
         begin
              write(l,' ');
              inc(l);
         end
         else
         begin
              write(r,' ');
              dec(r);
         end;
     writeln;
end.