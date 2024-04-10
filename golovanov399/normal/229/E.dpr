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
 a, b: array[1..100000] of integer;
 n, m, i, j, c, cnt, kk: integer;
 k, l: array[1..100000] of integer;
 p: extended;
 q: array[1..100000] of extended;
 lol: array[1..1000, 1..1000] of extended;
 xex: array[1..1000] of integer;

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
   swap(b[i], b[j]);
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
 readln(n, m);
 randomize;
 c := 0;
 for i := 1 to m do
 begin
  read(k[i]);
  for j := 1 to k[i] do
  begin
   inc(c);
   read(a[c]);
   b[c] := i;
  end;
 end;
 QSort(1, c);
 i := c - n + 1;
 j := i;
 while (j > 1) and (a[j - 1] = a[j]) do dec(j);
 cnt := i - j + 1;
 while (i < c) and (a[i + 1] = a[i]) do inc(i);
 kk := n + i - c;
 fillchar(l, sizeof(l), 0);
 while i < c do
 begin
  inc(i);
  inc(l[b[i]]);
 end;
 p := 1;
 for i := 1 to m do
 begin
  for j := 1 to l[i] do
  p := p * j / (k[i] + 1 - j);
  if l[i] = k[i] then q[i] := 0 else
  q[i] := (l[i] + 1) / (k[i] - l[i]);
 end;
 cnt := cnt + kk - 1;
 for i := 1 to cnt do
 xex[i] := b[c - n - cnt + kk + i];
 lol[1, 1] := q[xex[1]];
 for i := 2 to cnt do
 lol[1, i] := lol[1, i - 1] + q[xex[i]];
 for i := 2 to kk do
 begin
  lol[i, i] := lol[i - 1, i - 1] * q[xex[i]];
  for j := i + 1 to cnt do
  lol[i, j] := lol[i, j - 1] + q[xex[j]] * lol[i - 1, j - 1];
 end;
 p := p * lol[kk, cnt];
 for i := 1 to kk do
 p := p * i / (cnt + 1 - i);
 writeln(p:0:12);
end.