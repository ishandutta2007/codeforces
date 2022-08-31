{$APPTYPE CONSOLE}

var
 s: string;
 i: integer;

function qwe(x: char): boolean;
begin
 result:=(x<='z')and(x>='a')
end;

begin
 readln(s);
 for i:=2 to length(s) do
 begin
  if qwe(s[i]) then
  begin
   writeln(s);
   readln;
   halt(0);
  end;
 end;
 if qwe(s[1]) then
 write(chr(ord(s[1]) + ord('A') - ord('a'))) else
 write(chr(ord(s[1]) + ord('a') - ord('A')));
 for i:=2 to length(s) do
 write(chr(ord(s[i]) + ord('a') - ord('A')));
 readln;
end.