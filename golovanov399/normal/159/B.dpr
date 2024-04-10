program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

var
 n, m, i, j, x, y: integer;
 a, b: array[1..1000, 1..1000] of integer;
 c, d: array[1..1000] of integer;

begin
 readln(n, m);
 fillchar(a, sizeof(a), 0);
 fillchar(b, sizeof(b), 0);
 fillchar(c, sizeof(c), 0);
 fillchar(d, sizeof(d), 0);
 for i := 1 to n do
 begin
  readln(x, y);
  inc(a[x, y]);
  inc(c[y]);
 end;
 for i := 1 to m do
 begin
  readln(x, y);
  inc(b[x, y]);
  inc(d[y]);
 end;
 x := 0;
 y := 0;
 for i := 1 to 1000 do
 begin
  x := x + min(c[i], d[i]);
  for j := 1 to 1000 do
  y := y + min(a[j, i], b[j, i]);
 end;
 writeln(x, ' ', y);
end.