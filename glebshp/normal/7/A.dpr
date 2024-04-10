program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$O+,Q-,R-,M+,I-}
//{$O-,Q+,R+,M+,I+}


uses
  SysUtils;

var
  field : array[1 .. 8, 1 .. 8] of char;
  i, j, cnt, ans : integer;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  cnt := 0;
  for i := 1 to 8 do
  begin
    for j := 1 to 8 do
    begin
      read(field[i, j]);
      if field[i, j] = 'B' then
        inc(cnt);
    end;
    readln;
  end;
  if cnt = 64 then
    writeln('8')
  else
  begin
    ans := 0;
    for i := 1 to 8 do
    begin
      cnt := 0;
      for j := 1 to 8 do
        if field[i, j] = 'B' then
          inc(cnt);
      if cnt = 8 then
        inc(ans);
    end;
    for i := 1 to 8 do
    begin
      cnt := 0;
      for j := 1 to 8 do
        if field[j, i] = 'B' then
          inc(cnt);
      if cnt = 8 then
        inc(ans);
    end;
    writeln(ans);
  end;
end.