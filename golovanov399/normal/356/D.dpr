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
 n, i, j, s, mx: integer;
 a, p, c, ar: array[1..100000] of integer;
 b, boo: array[0..100000] of boolean;
 next, prev: array[1..100000] of integer;

procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := a[random(r - l + 1) + l];
 repeat
  while a[i] < x do inc(i);
  while a[j] > x do dec(j);
  if (i <= j) then
  begin
   swap(a[i], a[j]);
   swap(p[i], p[j]);
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
 readln(n, s);
 for i := 1 to n do read(a[i]);
 for i := 1 to n do p[i] := i;
 QSort(1, n);
 if s < a[n] then panic;
 s := s - a[n];
 dec(n);
 b[0] := true;
 for i := 1 to s do b[i] := false;
 for i := 1 to s do
 begin
  prev[i] := i - 1;
  next[i] := i + 1;
 end;
 mx := 0;
 for i := 1 to n do
 if not b[s] then
 begin
  j := min(mx + a[i], s);
  while ((j >= a[i]) and (b[j])) do dec(j);
  while (j >= a[i]) do
  begin
   if b[j - a[i]] then
   begin
    b[j] := true;
    c[j] := i;
    mx := max(mx, j);
    next[prev[j]] := next[j];
    prev[next[j]] := prev[j];
   end;
   j := prev[j];
  end;
  if b[s] then break;
 end;
 if not b[s] then panic;
 for i := 1 to n do boo[i] := false;
 i := s;
 while (i > 0) do
 begin
  boo[p[c[i]]] := true;
  i := i - a[c[i]];
 end;
 boo[p[n + 1]] := true;
 inc(n);
 for i := 1 to n do
 begin
  if ((i > 1) and (boo[p[i - 1]] = false)) then c[p[i]] := p[i - 1] else c[p[i]] := 0;
//  if ((i > 1) and (b[i - 1] = false)) then a[i] := a[i] - a[i - 1];
 end;
 for i := 1 to n do ar[p[i]] := a[i];
 for i := 1 to n do
 begin
  if c[i] > 0 then write(ar[i] - ar[c[i]], ' ') else write(ar[i], ' ');
//  write(ar[i], ' ');
  if c[i] = 0 then writeln('0') else writeln('1 ', c[i]);
 end;
end.