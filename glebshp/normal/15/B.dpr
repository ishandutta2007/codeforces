program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  t, i : integer;
  n, m, x1, y1, x2, y2, dx, dy, ans : int64;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(t);
  for i := 1 to t do
  begin
    read(n, m, x1, y1, x2, y2);
    dx := abs(x2 - x1);
    dy := abs(y2 - y1);
    ans := (n - dx) * (m - dy) * 2;
    if (n - dx > n div 2) and (m - dy > m div 2) then
      dec(ans, (dx * 2 - n) * (dy * 2 - m));
    ans := n * m - ans;
    //ans := dx * dy * 2;
    //if (dx * 2 > n) and (dy * 2 > m) then
    //  dec(ans, (dx * 2 - n) * (dy * 2 - m));
    writeln(ans);
  end;
end.