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
 n, m, k, x, i, j, ij, _: integer;
 a, b: array[1..100] of int64;
 c: array[1..100, 1..16] of int64;
 d: array[0..50, 0..50, 1..16] of int64;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(k, x, n, m);
 a[1] := 1;
 a[2] := 0;
 b[1] := 0;
 b[2] := 1;
 for i := 1 to 16 do
 begin
  c[1][i] := 0;
  c[2][i] := 0;
 end;
 for i := 3 to k do
 begin
  a[i] := a[i - 1] + a[i - 2];
  b[i] := b[i - 1] + b[i - 2];
  if (i = 3) then
  begin
   for j := 1 to 16 do c[i][j] := 0;
   c[i][7] := 1;
   c[i][8] := 1;
   c[i][15] := 1;
   c[i][16] := 1;
  end else
  begin
   for j := 1 to 16 do
   begin
    if ((j mod 2 = 0) and (((i mod 2 = 0) and (j > 8)) or ((i mod 2 <> 0) and ((j - 1) mod 4 > 1)))) then c[i][j] := c[i - 1][j] + c[i - 2][j] + 1 else
    c[i][j] := c[i - 1][j] + c[i - 2][j];
   end;
  end;
 end;
 for i := 0 to n div 2 do
 for j := 0 to m div 2 do
 for ij := 1 to 16 do
 d[i][j][ij] := a[k] * i + b[k] * j + c[k][ij];
 for ij := 1 to 16 do
 if (((ij < 13) or (n > 1)) and ((ij mod 4 <> 0) or (m > 1))) then
 for i := 0 to (n - ((ij + 3) div 8)) div 2 do
 for j := 0 to (m - (((ij - 1) mod 4 + 1) div 2)) div 2 do
 if d[i][j][ij] = x then
 begin
  if (ij > 8) then write('C');
  for _ := 1 to i do write('AC');
  for _ := 1 to (n - ((ij + 3) div 8)) - i - i do write('B');
  if ((ij - 1) mod 8) > 3 then write('A');
  writeln;
  if ((ij - 1) mod 4) > 1 then write('C');
  for _ := 1 to j do write('AC');
  for _ := 1 to (m - (((ij - 1) mod 4 + 1) div 2)) - j - j do write('B');
  if (ij mod 2 = 0) then write('A');
  halt(0);
 end;
 writeln('Happy new year!');
end.