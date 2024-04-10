program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
//{$O-,Q+,R+,M+,I+}
{$O+,Q-,R-,M+,I-}

uses
  SysUtils, StrUtils;

var
  line, f, s : string;
  flag1, flag2 : boolean;
  i, j : integer;

function can(var line, pat : string; p : integer) : boolean;
var
  i : integer;
begin
  for i := 1 to length(pat) do
    if line[i + p - 1] <> pat[i] then
    begin
      can := false;
      exit;
    end;
  can := true;
end;

begin
  //reset(input,'input.txt');
  //write(output,'output.txt');
  readln(line);
  readln(f);
  readln(s);
  flag1 := false;
  flag2 := false;
  for i := 1 to length(line) - length(f) + 1 do
    if can(line, f, i) then
    begin
      for j := i + length(f) to length(line) - length(s) + 1 do
        if can(line, s, j) then
        begin
          flag1 := true;
          break;
        end;
      break;
    end;
  line := reversestring(line);
  for i := 1 to length(line) - length(f) + 1 do
    if can(line, f, i) then
    begin
      for j := i + length(f) to length(line) - length(s) + 1 do
        if can(line, s, j) then
        begin
          flag2 := true;
          break;
        end;
      break;
    end;
  if flag1 and flag2 then
    writeln('both')
  else
    if not flag1 and not flag2 then
      writeln('fantasy')
    else
      if flag1 then
        writeln('forward')
      else
        writeln('backward');

end.