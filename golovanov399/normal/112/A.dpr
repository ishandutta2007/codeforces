{$APPTYPE CONSOLE}

var
 s, t: string;
 i: integer;

begin
 readln(s);
 readln(t);
 for i:=1 to length(s) do
 if (s[i] >= 'a') and (s[i] <= 'z') then
 s[i]:=chr(ord(s[i]) + ord('A') - ord('a'));
 for i:=1 to length(t) do
 if (t[i] >= 'a') and (t[i] <= 'z') then
 t[i]:=chr(ord(t[i]) + ord('A') - ord('a'));
 if s<t then writeln(-1) else
 if s>t then writeln(1) else
 writeln(0);
end.