var s, t: ansistring;
        s_bool, t_bool: array [1..1000] of boolean;
        i: integer;
        ans: boolean;
begin
readln(s); readln(t);
if length(s)<>length(t) then
        begin
        writeln('No');
        halt;
        end;
for i:=1 to length(s) do
        begin
        if (s[i]='a') or (s[i]='e') or (s[i]='i') or (s[i]='o') or (s[i]='u') then s_bool[i]:=true
        else s_bool[i]:=false;
        if (t[i]='a') or (t[i]='e') or (t[i]='i') or (t[i]='o') or (t[i]='u') then t_bool[i]:=true
        else t_bool[i]:=false;
        end;
ans:=true;
for i:=1 to length(s) do
        if s_bool[i]<>t_bool[i] then ans:=false;
if ans then writeln('Yes') else writeln('No');
end.