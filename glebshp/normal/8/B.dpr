program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$O-,Q+,R+,M+,I+}
//{$O+,Q-,R-,M+,I-}

uses
  SysUtils;

const
  size = 1000;

var
  used : array[- size .. size, - size .. size] of boolean;
  x, y, i : integer;
  line : string;

function count_nb(x, y : integer) : integer;
var
  cnt, i, j : integer;
begin
  cnt := 0;
  for i := -1 to 1 do
    for j := -1 to 1 do
      if (i * j = 0) and (i + j <> 0) and used[x + i, y + j] then
        inc(cnt);
  count_nb := cnt;
end;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(line);
  x := 0;
  y := 0;
  for i := 1 to length(line) do
  begin
    used[x, y] := true;
    case line[i] of
    'L' : dec(x);
    'R' : inc(x);
    'U' : inc(y);
    'D' : dec(y);
    end;
    if used[x, y] or (count_nb(x, y) > 1) then
    begin
      writeln('BUG');
      halt(0);
    end;
  end;
  writeln('OK');
end.