program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  i, n, p1, p2, p3, t1, t2, l, r, last, ans, d : integer;

begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(n, p1, p2, p3, t1, t2);
  last := 0;
  ans := 0;
  for i := 1 to n do
  begin
    read(l, r);
    inc(ans, (r - l) * p1);
    if i <> 1 then
    begin
      d := l - last;
      inc(ans, min(d, t1) * p1);
      d := max(0, d - t1);
      inc(ans, min(d, t2) * p2);
      d := max(0, d - t2);
      inc(ans, d * p3);
    end;
    last := r;
  end;
  writeln(ans);
end.