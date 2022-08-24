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
 n, m, k, g: integer;
 ans, v, s: int64;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m, g);
 ans := 0;
 if m = 0 then
 begin
  writeln(g xor (n mod 2));
  halt(0);
 end;
 m := m - 1;
 if m = 0 then
 begin
  if g = 0 then ans := (n + 1) div 2 else ans := n div 2;
  if (n + 1) mod 2 = g then inc(ans);
  writeln(ans);
  halt(0);
 end;
 k := (n + g) mod 2;
 if k = 0 then s := 1 else s := m + 1;
 while n >= k do
 begin
  ans := ans + s;
  v := (k + m + 2);
  v := v * (v - 1) mod base;
  s := (s * v) mod base;
  v := k + 2;
  v := v * (k + 1) mod base;
  v := sqrr(v, base - 2);
  s := (s * v) mod base;
  k := k + 2;
 end;
 writeln(ans mod base);
end.