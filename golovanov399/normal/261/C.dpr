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

function c(n, k: integer): int64;
var
 s: int64;
 i: integer;
begin
 s := 1;
 for i := 1 to k do
 s := (s * (n + 1 - i)) div i;
 result := s;
end;

var
 n, t: int64;
 m, k: integer;
 v: int64;
 s: int64;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, t);
 inc(n);
 if t = 1 then s := -1 else s := 0;
 v := 1;
 k := 0;
 while (v < t) do
 begin
  v := v * 2;
  k := k + 1;
 end;
 if v > t then
 begin
  writeln(0);
  halt(0);
 end;
 v := 1;
 m := 0;
 while (2 * v - 1 <= n) do
 begin
  inc(m);
  v := v * 2;
 end;
 s := s + c(m, k + 1);
 n := n - v + 1;
 while (v > 1) do
 begin
  v := v div 2;
  dec(m);
  if n >= v then
  begin
   s := s + c(m, k);
   n := n - v;
   k := k - 1;
   if k < 0 then
   begin
    writeln(s);
    halt(0);
   end;
  end;
 end;
 writeln(s);
end.