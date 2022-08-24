{$APPTYPE CONSOLE}

uses
 SysUtils;

var
 s: string;
 x, y, i: integer;
 
begin
 readln(s);
 readln(x);
 for i := 1 to length(s) do
 begin
  if ((s[i] >= 'a') and (s[i] <= 'z')) then
  y := ord(s[i]) - ord('a') + 1 else
  y := ord(s[i]) - ord('A') + 1;
  if y <= x then write(upcase(s[i])) else write(lowercase(s[i]));
 end;
 writeln;
end.