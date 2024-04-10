var a: int64;
        res, q, i: integer;
begin
readln(q);
for i:=1 to q do
begin
readln(a); res:=0;
while a mod 2 = 0 do
        begin
        a:=a div 2;
        res:=res+1;
        end;
while a mod 3 = 0 do
        begin
        a:=a div 3;
        res:=res+2;
        end;
while a mod 5 = 0 do
        begin
        a:=a div 5;
        res:=res+3;
        end;
if a<>1 then writeln('-1') else writeln(res);
end;end.