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
 n, m, k, i, j, x: integer;
 a, b: array[1..100000] of integer;

procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := a[l + random(r - l + 1)];
 repeat
  while a[i] < x do inc(i);
  while a[j] > x do dec(j);
  if i <= j then
  begin
   swap(a[i], a[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort(l, j);
 QSort(i, r);
end;

procedure QSort2(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := b[l + random(r - l + 1)];
 repeat
  while b[i] < x do inc(i);
  while b[j] > x do dec(j);
  if i <= j then
  begin
   swap(b[i], b[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort2(l, j);
 QSort2(i, r);
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m, k);
 fillchar(a, sizeof(a), 0);
 fillchar(b, sizeof(b), 0);
 for i := 1 to n do
 read(a[i]);
 for i := 1 to m do
 read(b[i]);
 if n > m then
 begin
  writeln('YES');
  halt(0);
 end;
 randomize;
 QSort(1, n);
 QSort2(1, m);
 x := 0;
 i := n;
 j := m;
 while ((i > 0) or (j > 0)) do
 begin
  if ((j = 0) or ((i > 0) and (a[i] > b[j]))) then dec(x) else inc(x);
  if ((j = 0) or ((i > 0) and (a[i] > b[j]))) then dec(i) else dec(j);
  if x < 0 then
  begin
   writeln('YES');
   halt(0);
  end;
 end;
 writeln('NO');
end.