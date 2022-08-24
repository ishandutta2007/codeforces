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
 n, m, i, j, k: integer;
 l, r, x: array[1..300265] of integer;
 a: array[1..1048576] of integer;

procedure paint(v, l, r, l1, r1, x: integer);
var
 m: integer;
begin
 if l1 > r1 then exit;
 if ((l1 = l) and (r1 = r)) then
 begin
  a[v] := x;
  exit;
 end;
 if a[v] <> 0 then
 begin
  a[2 * v] := a[v];
  a[2 * v + 1] := a[v];
  a[v] := 0;
 end;
 m := (l + r) div 2;
 if (m < l1) then
 paint(2 * v + 1, m + 1, r, l1, r1, x) else
 if (m >= r1) then
 paint(2 * v, l, m, l1, r1, x) else
 begin
  paint(2 * v, l, m, l1, m, x);
  paint(2 * v + 1, m + 1, r, m + 1, r1, x);
 end;
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m);
 for i := 1 to m do readln(l[i], r[i], x[i]);
 for i := 1 to n + 524288 do a[i] := 0;
 for i := m downto 1 do
 begin
  paint(1, 1, 524288, l[i], x[i] - 1, x[i]);
  paint(1, 1, 524288, x[i] + 1, r[i], x[i]);
 end;
 for i := 1 to n do
 begin
  j := 524287 + i;
  k := 0;
  while (j > 0) do
  begin
   if a[j] > 0 then k := a[j];
   j := j div 2;
  end;
  write(k, ' ');
 end;
end.