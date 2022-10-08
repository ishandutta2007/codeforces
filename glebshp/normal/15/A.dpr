program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  size = 1000;

var
  x, a : array[1 .. size] of integer;
  sp, i, j, n, t, ans : integer;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, t);
  for i := 1 to n do
    read(x[i], a[i]);
  for i := 1 to n -1 do
    for j := 1 to n - i do
    begin
      if x[j] > x[j + 1] then
      begin
        sp := x[j];
        x[j] := x[j + 1];
        x[j + 1] := sp;
        sp := a[j];
        a[j] := a[j + 1];
        a[j + 1] := sp;
      end;
    end;
  ans := 2;
  for i := 1 to n - 1 do
  begin
    if (x[i + 1] - x[i]) * 2 >= (a[i + 1] + a[i] + t * 2) then
      inc(ans);
    if (x[i + 1] - x[i]) * 2 > (a[i + 1] + a[i] + t * 2) then
      inc(ans);
  end;
  writeln(ans);
end.