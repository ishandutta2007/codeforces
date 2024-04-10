program asdfsdf;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
 n, m, i, j, x, y, z, s: integer;
 a: array[1..50, 1..50] of integer;
 b, c, prb, prc: array[0..50] of integer;

function qwe(q, w, e: integer): boolean;
begin
 result := ((q = x) and (w = y) and (e = z)) or ((q = x) and (w = z) and (e = y)) or ((q = y) and (w = x) and (e = z)) or ((q = y) and (w = z) and (e = x)) or ((q = z) and (w = x) and (e = y)) or ((q = z) and (w = y) and (e = x));
end;

function sumb(l, r: integer): integer;
begin
 result := prb[r] - prb[l - 1];
end;

function sumc(l, r: integer): integer;
begin
 result := prc[r] - prc[l - 1];
end;

begin
 reset(input,'input.txt');
 rewrite(output,'output.txt');
 readln(n, m);
 fillchar(a, sizeof(a), 0);
 fillchar(b, sizeof(b), 0);
 fillchar(c, sizeof(c), 0);
 s := 0;
 for i := 1 to n do
 for j := 1 to m do
 begin
  read(a[i, j]);
  b[i] := b[i] + a[i, j];
  c[j] := c[j] + a[i, j];
  s := s + a[i, j];
 end;
 read(x, y, z);
 if x + y + z <> s then
 begin
  writeln(0);
  halt(0);
 end;
 prb[1] := b[1];
 for i := 2 to n do
 prb[i] := prb[i - 1] + b[i];
 prc[1] := c[1];
 for i := 2 to m do
 prc[i] := prc[i - 1] + c[i];
 prb[0] := 0;
 prc[0] := 0;
 s := 0;
 for i := 1 to n - 2 do
 for j := i + 1 to n - 1 do
 begin
  if qwe(sumb(1, i), sumb(i + 1, j), sumb(j + 1, n)) then inc(s);
 end;
 for i := 1 to m - 2 do
 for j := i + 1 to m - 1 do
 begin
  if qwe(sumc(1, i), sumc(i + 1, j), sumc(j + 1, m)) then inc(s);
 end;
 writeln(s);
end.