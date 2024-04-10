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

procedure panic;
begin
 writeln('NO');
 halt(0);
end;

var
 n, t1, t2, k, i, j: integer;
 a, b, t, num: array[1..1000] of integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, t1, t2, k);
 for i := 1 to n do
 begin
  readln(a[i], b[i]);
  if (b[i] * t1 * (100 - k) + 100 * a[i] * t2) > (a[i] * t1 * (100 - k) + b[i] * t2 * 100) then
  swap(a[i], b[i]);
  t[i] := (a[i] * t1 * (100 - k) + b[i] * t2 * 100);
  num[i] := i;
 end;
 for i := 1 to n - 1 do
 for j := i + 1 to n do
 if (t[j] > t[i]) or ((t[j] = t[i]) and (num[j] < num[i])) then
 begin
  swap(t[i], t[j]);
  swap(num[i], num[j]);
 end;
 for i := 1 to n do
 if t[i] mod 100 < 10 then
 writeln(num[i], ' ', t[i] div 100, '.0', t[i] mod 100) else
 writeln(num[i], ' ', t[i] div 100, '.', t[i] mod 100);
end.