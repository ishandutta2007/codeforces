program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

const base = 1000000007;
 eps = 1e-8;

type
 TArray = array[0..1000010] of integer;
 int53 = int64;
 itneger = integer;
 point = record
  x, y: integer;
 end;
 
function sqrr(a, b: integer): int64;
var
 dega, res: int64;
begin
 res := 1;
 dega := a;
 while b > 0 do
 begin
  if odd(b) then res := res * dega;
  dega := dega * dega;
  b := b div 2;
  res := res mod base;
  dega := dega mod base;
 end;
 result := res mod base;
end;

procedure swap(var x, y: integer);
var
 z: integer;
begin
 z := x;
 x := y;
 y := z;
end;

procedure swap64(var x, y: int64);
var
 z: int64;
begin
 z := x;
 x := y;
 y := z;
end;

procedure swapex(var x, y: extended);
var
 z: extended;
begin
 z := x;
 x := y;
 y := z;
end;

(*
procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := l + random(r - l + 1);
 repeat
  while (m[i] > m[x]) or ((m[i] = m[x]) and (v[i] > v[x])) do inc(i);
  while (m[j] < m[x]) or ((m[j] = m[x]) and (v[j] < v[x])) do dec(j);
  if i <= j then
  begin
   swap(m[i], m[j]);
   swap(v[i], v[j]);
   swap(num[i], num[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort(l, j);
 QSort(i, r);
end;
*)

var
 a, s: array[0..500, 0..500] of integer;
 n, m, i, j, mm, x, y: integer;

function sum(x1, y1, x2, y2: integer): integer;
begin
 result := s[x2, y2] - s[x1 - 1, y2] - s[x2, y1 - 1] + s[x1 - 1, y1 - 1];
end;

begin
 readln(n, m);
 for i := 1 to n do
 for j := 1 to m do
 read(a[i, j]);
 fillchar(s, sizeof(s), 0);
 s[1, 1] := a[1, 1];
 for i := 2 to m do
 s[1, i] := s[1, i - 1] + a[1, i];
 for i := 2 to n do
 s[i, 1] := s[i - 1, 1] + a[i, 1];
 for i := 2 to n do
 for j := 2 to m do
 s[i, j] := s[i, j - 1] + s[i - 1, j] - s[i - 1, j - 1] + a[i, j];
 mm := -2000000000;
 for i := 2 to n - 1 do
 for j := 2 to m - 1 do
 begin
  y := 2;
  x := sum(i - 1, j - 1, i + 1, j + 1) - sum(i, j - 1, i, j);
  if x > mm then mm := x;
  while (i - y > 0) and (i + y <= n) and (j - y > 0) and (j + y <= m) do
  begin
   x := sum(i - y, j - y, i + y, j + y) - x - a[i - y + 1, j - y];
   if x > mm then
   mm := x;
   inc(y);
  end;
 end;
 writeln(mm);
end.