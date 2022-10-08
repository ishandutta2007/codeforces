program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  size = 1000 * 1000;

var
  primary : array[1 .. size] of boolean;
  mas : array[1 .. size] of integer;
  i, j, n, k, len, cnt : integer;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(n, k);
  for i := 2 to n do
    primary[i] := true;
  for i := 2 to n do
    if primary[i] then
    begin
      j := i;
      while i * j <= n do
      begin
        primary[i * j] := false;
        inc(j);
      end;
    end;
  len := 0;
  for i := 2 to n do
    if primary[i] then
    begin
      inc(len);
      mas[len] := i;
    end;
  cnt := 0;
  for i := 1 to len do
    for j := 1 to len + 1 do
      if mas[i] = mas[j] + mas[j + 1] + 1 then
      begin
        inc(cnt);
        break;
      end;
  if k <= cnt then
    writeln('YES')
  else
    writeln('NO');
end.