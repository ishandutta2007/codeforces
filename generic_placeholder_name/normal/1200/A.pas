var n, i, j, k: integer;
    s: string;
    r: array [1..10] of boolean;
begin
    readln(n); readln(s);
    for i:=1 to 10 do r[i]:=false;
    for i:=1 to n do
        begin
        if (s[i]='R') then
            begin
            for j:=10 downto 1 do
                if not r[j] then
                    begin
                    r[j]:=true; break;
                    end;
            end
        else if (s[i]='L') then
             begin
             for k:=1 to 10 do
                 if not r[k] then
                    begin
                    r[k]:=true; break;
                    end;
             end
        else r[ord(s[i])-47]:=false;
        end;
    for i:=1 to 10 do
        if r[i] then write(1) else write(0);
end.