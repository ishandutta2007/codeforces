program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

//it is a big shablon. if you see any strange function, never mind

const base = 1000000007;
 eps = 1e-8;
 inf = 1 shl 30;

type
 TArray = array[0..10000010] of integer;
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

function less(x, y: point): boolean;
begin
 if (x.x < y.x) or ((x.x = y.x) and (x.y < y.y)) then result := true else result := false;
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

procedure swapp(var x, y: point);
var
 z: point;
begin
 z := x;
 x := y;
 y := z;
end;

var
 n, m, k, i, j, l: integer;
 x, y, ans: integer;
 a, b, c: array[0..100, 0..100] of integer;
 ar, cn: array[0..100] of integer;

procedure sort;
var
 i, j: integer;
begin
 for i := 1 to m - 1 do
 for j := i + 1 to m do
 if ar[i] < ar[j] then
 begin
  swap(ar[i], ar[j]);
  swap(cn[i], cn[j]);
 end;
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input,'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m, k);
 for i := 1 to n do
 begin
  readln;
  for j := 1 to m do
  readln(a[i, j], b[i, j], c[i, j]);
 end;
 ans := 0;
 for i := 1 to n do
 for j := 1 to n do
 begin
  for l := 1 to m do
  begin
   ar[l] := b[j, l] - a[i, l];
   cn[l] := c[i, l];
  end;
  sort;
  x := 0;
  y := k;
  l := 1;
  while (l <= m) and (y > 0) and (ar[l] > 0) do
  begin
   x := x + ar[l] * min(y, cn[l]);
   y := y - cn[l];
   inc(l);
  end;
  if x > ans then ans := x;
 end;
 writeln(ans);
end.