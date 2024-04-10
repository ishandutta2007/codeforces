program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;

const
  size = 2 * 1000;

var
  mas : array[1 .. size] of integer;
  ans, i, n, d, c : integer;

begin
  //  reset(input,'input.txt');
  //  rewrite(output,'output.txt');
  read(n, d);
  for i := 1 to n do
    read(mas[i]);
  ans := 0;
  for i := 2 to n do
  begin
    c := max(0, mas[i- 1] - mas[i]) div d;
    inc(ans, c);
    inc(mas[i], c * d);
    if mas[i] <= mas[i - 1] then
    begin
      inc(ans);
      inc(mas[i], d);
    end;
  end;
  writeln(ans);
end.