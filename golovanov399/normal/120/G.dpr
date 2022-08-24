program asdfsdf;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;

var
 n, m, i, j, t, tt, p, k: integer;
 a, b: array[1..200] of integer;
 c: array[1..100] of integer;
 d: array[1..100, 1..100] of integer;
 s: array[1..100] of string;
 were: array[1..100] of boolean;
 win: array[1..100, 0..100] of integer;

begin
 reset(input,'input.txt');
 rewrite(output,'output.txt');
 readln(n, t);
 for i := 1 to n do
 readln(a[i], b[i], a[i + n], b[i + n]);
 readln(m);
 for i := 1 to m do
 begin
  readln(s[i]);
  readln(c[i]);
 end;
 p := 0;
 i := 0;
 fillchar(were, sizeof(were), 0);
 fillchar(win, sizeof(win), 0);
 fillchar(d, sizeof(d), 0);
 k := 0;
 while k < m do
 begin
  i := i mod (2 * n) + 1;
  tt := t;
  while (tt > 0) and (k < m) do
  begin
   repeat
    p := p mod m + 1;
   until not were[p];
   if max(1, c[p] - a[i] - b[(i + (n - 1)) mod (2 * n) + 1] - d[(i - 1) mod n + 1, p]) <= tt then
   begin
    tt := tt - max(1, c[p] - a[i] - b[(i + (n - 1)) mod (2 * n) + 1] - d[(i - 1) mod n + 1, p]);
    inc(win[(i - 1) mod n + 1, 0]);
    win[(i - 1) mod n + 1, win[(i - 1) mod n + 1, 0]] := p;
    were[p] := true;
    inc(k);
   end else
   begin
    d[(i - 1) mod n + 1, p] := d[(i - 1) mod n + 1, p] + tt;
    tt := 0;
   end;
  end;
 end;
 for i := 1 to n do
 begin
  write(win[i, 0], ' ');
  for j := 1 to win[i, 0] do
  write(s[win[i, j]], ' ');
  writeln;
 end;
end.