program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}
{$O-}

uses
  SysUtils,
  Math;

//it is a big shablon. if you see any strange function, never mind

const base = 1000000007;
 eps = 1e-8;
 inf = 1 shl 30;
 trye = true;

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

function gcd(x, y: integer): integer;
begin
 while ((x > 0) and (y > 0)) do
 begin
  if x > y then x := x mod y else y := y mod x;
 end;
 result := x + y;
end;

function nok(x, y: integer): int64;
var
 v: int64;
begin
 v := x;
 v := v * y;
 v := v div gcd(x, y);
 result := v;
end;

procedure panic;
begin
 writeln(-1);
 halt(0);
end;

var
 n, m, i, j, k: integer;
 a: array[0..501, 0..501] of char;
 x, y: array[1..250000] of integer;
 l, r: integer;
 b: array[0..501, 0..501] of boolean;
 xx, yy: array[1..4] of integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m, k);
 for i := 1 to n do
 begin
  for j := 1 to m do
  read(a[i, j]);
  readln;
 end;
 l := 1;
 r := 1;
 for i := 1 to n do
 for j := 1 to m do
 if a[i, j] = '.' then
 begin
  x[1] := i;
  y[1] := j;
 end;
 fillchar(b, sizeof(b), 0);
 b[x[1], y[1]] := true;
 xx[1] := 0;
 xx[2] := 1;
 xx[3] := 0;
 xx[4] := -1;
 yy[1] := 1;
 yy[2] := 0;
 yy[3] := -1;
 yy[4] := 0;
 while (r >= l) do
 begin
  for i := 1 to 4 do
  if ((a[x[l] + xx[i], y[l] + yy[i]] = '.') and (b[x[l] + xx[i], y[l] + yy[i]] = false)) then
  begin
   inc(r);
   x[r] := x[l] + xx[i];
   y[r] := y[l] + yy[i];
   b[x[r], y[r]] := true;
  end;
  inc(l);
 end;
 for i := 1 to k do
 a[x[r + 1 - i], y[r + 1 - i]] := 'X';
 for i := 1 to n do
 begin
  for j := 1 to m do
  write(a[i, j]);
  writeln;
 end;
end.