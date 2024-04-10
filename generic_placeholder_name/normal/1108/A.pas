var t, i, l1, r1, l2, r2: longint;
begin
readln(t);
for i:=1 to t do
        begin
        readln(l1, r1, l2, r2);
        write(l1, ' ');
        if l1=l2 then writeln(l2+1)
        else writeln(l2);
        end;
end.