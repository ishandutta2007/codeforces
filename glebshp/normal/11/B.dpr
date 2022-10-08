program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  x, sum, cnt : integer;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(x);
  x := abs(x);
  sum := 0;
  cnt := 0;
  while (sum < x) or ((sum - x) mod 2 = 1) do
  begin
    inc(cnt);
    inc(sum, cnt);
  end;
  writeln(cnt);
end.