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
 n, l, t, i, j, k: integer;
 a: array[1..1000000] of itneger;
 m, v: int64;
 x: extended;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, l, t);
 if n = 1 then
 begin
  writeln('0.000000');
  halt(0);
 end;
 for i := 1 to n do read(a[i]);
 m := 0;
 k := (2 * t) mod l;
 i := 1;
 j := 2;
 while i <= n do
 begin
  if j = i - 1 then j := j mod n + 1;
  if j = i then j := j mod n + 1;
  while (((j > i) and (a[j] - a[i] <= k)) or ((j < i) and (a[j] - a[i] + l <= k))) do j := j mod n + 1;
  j := j - 1;
  if j = 0 then j := n;
  v := j - i;
  if v < 0 then v := v + n;
  m := m + v;
  inc(i);
 end;
 x := n;
 x := x * (n - 1);
 x := x * ((2 * t) div l);
 x := x + m;
 x := x / 4;
 writeln(x:0:8);
end.