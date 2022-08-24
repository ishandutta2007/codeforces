program qwe123;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
 s, t: string;
 i: integer;
 b: boolean;

begin
 readln(s);
 t:='';
 b:=false;
 for i:=1 to length(s) do
 begin
  if (s[i] <> ' ')and(s[i] <> '.')and(s[i] <> ',')and(s[i] <> '?')and(s[i] <> '!') then
  begin
   if (t = '')and(b) then write(' ');
   t := t + s[i];
  end else
  begin
   if t <> '' then write(t);
   if t <> '' then b := true;
   t := '';
   if s[i] <> ' ' then write(s[i]);
  end;
 end;
 write(t);
end.