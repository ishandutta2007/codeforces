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
 writeln('Error occurred');
 halt(0);
end;

var
 n, k, i: integer;
 b, s, t: int64;
 a: array[1..100000] of integer;
 num, qw: array[1..100000] of integer;
 was: array[1..100000] of boolean;

procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := a[l + random(r - l + 1)];
 repeat
  while a[i] > x do inc(i);
  while a[j] < x do dec(j);
  if i <= j then
  begin
   swap(a[i], a[j]);
   swap(num[i], num[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort(l, j);
 QSort(i, r);
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, k);
 readln(b);
 for i := 1 to n do
 read(a[i]);
 for i := 1 to n do num[i] := i;
 randomize;
 QSort(1, n - 1);
 for i := 1 to n do qw[num[i]] := i;
// for i := 1 to n - 1 do write(a[i], ' ');
// writeln;
 fillchar(was, sizeof(was), 0);
 s := 0;
 for i := 1 to k do
 begin
  was[num[i]] := true;
  s := s + a[i];
 end;
 for i := 1 to n - 1 do
 begin
  if was[i] then t := s else t := s - a[k] + a[qw[i]];
  if t > b then
  begin
   writeln(i);
   halt(0);
  end;
 end;
 writeln(n);
end.