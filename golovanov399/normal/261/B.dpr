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

function sqrr(a, b: int64): int64;
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

procedure panic;
begin
 writeln(-1);
 halt(0);
end;

var
 n, i, j, p, ij: integer;
 a: array[1..100] of integer;
 ar: array[0..100, 0..100, 0..100] of extended;
 pp: array[1..100] of extended;
 x, y: extended;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n);
 for i := 1 to n do
 read(a[i]);
 read(p);
// for i := 1 to n - 1 do
// for j := i + 1 to n do
// if a[i] > a[j] then
// swap(a[i], a[j]);
 fillchar(ar, sizeof(ar), 0);
 for i := 1 to n do
 for j := 0 to p do
 for ij := 0 to i do
 begin
  if ij = 0 then
  begin
   ar[i, j, ij] := 1;
  end else
  if i = 1 then
  begin
   if a[i] <= j then ar[i, j, ij] := 1 else ar[i, j, ij] := 0;
  end else
  begin
   if j - a[i] >= 0 then
   x := ar[i - 1, j - a[i], ij - 1] else
   x := 0;
   if i - 1 >= ij then
   y := ar[i - 1, j, ij] else
   y := 0;
   ar[i, j, ij] := (ij * x + (i - ij) * y) / i;
  end;
 end;
 x := 1;
 for i := 1 to n do
 begin
  pp[i] := ar[n, p, i] * x;
//  x := x * i / (n + 1 - i);
 end;
 pp[n + 1] := 0;
 x := 0;
 for i := 1 to n do
 x := x + i * (pp[i] - pp[i + 1]);
 writeln(x:0:6);
{
 for i := 1 to n do
 begin
  for j := 1 to p do
  begin
   for ij := 1 to n do
   write(ar[i, j, ij]:0:4, ' ');
   writeln;
  end;
  writeln;
 end; }
end.