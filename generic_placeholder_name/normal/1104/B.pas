var s, tmp: ansistring;
        i, c, l: longint;
begin
readln(s); tmp:='0';
for i:=1 to length(s) do
        begin
        tmp:=tmp+s[i];
        l:=length(tmp);
        if tmp[l-1]=tmp[l] then
                begin
                delete(tmp, l-1, 2);
                c:=c+1;
                end;
        end;
if c mod 2 = 1 then writeln('Yes')
else writeln('No');
end.