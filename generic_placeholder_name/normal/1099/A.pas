var w, h, u1, d1, u2, d2, tmp, i: longint;
begin
readln(w, h);
readln(u1, d1);
readln(u2, d2);
if d2>d1 then
        begin
        tmp:=d2; d2:=d1; d1:=tmp;
        tmp:=u2; u2:=u1; u1:=tmp;
        end;
for i:=d1 to h do w:=w+i;
w:=w-u1; if w<0 then w:=0;
for i:=d2 to d1-1 do w:=w+i;
w:=w-u2; if w<0 then w:=0;
for i:=0 to d2-1 do w:=w+i;
writeln(w);
end.