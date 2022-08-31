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
 n, i: integer;
 s, x, m: integer;
 a: array[1..100000] of integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n);
 for i := 1 to 2 * n - 1 do read(a[i]);
 s := 0;
 if n mod 2 = 1 then
 begin
  for i := 1 to 2 * n - 1 do s := s + abs(a[i]);
 end else
 begin
  m := 1000000000;
  for i := 1 to 2 * n - 1 do
  if abs(a[i]) < m then m := abs(a[i]);
  x := 0;
  for i := 1 to 2 * n - 1 do if a[i] < 0 then x := x xor 1;
  for i := 1 to 2 * n - 1 do if a[i] = 0 then x := 0;
  for i := 1 to 2 * n - 1 do s := s + abs(a[i]);
  if x = 1 then
  s := s - 2 * m;
 end;
 writeln(s);
end.