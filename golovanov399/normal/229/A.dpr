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
 n, m, i, j, k, ans, c, d: integer;
 ch: char;
 a: array[1..110, 1..10010] of shortint;
 b: array[1..110, 1..10010, 1..2] of integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m);
 for i := 1 to n do
 begin
  k := 1;
  for j := 1 to m do
  begin
   read(ch);
   a[i, j] := ord(ch) - ord('0');
   k := k * (1 - a[i, j]);
  end;
  if k = 1 then panic;
  readln;
 end;
 for i := 1 to n do
 begin
  j := 1;
  while a[i, j] = 0 do inc(j);
  b[i, j][1] := j;
  while j < m do
  begin
   inc(j);
   if a[i, j] = 1 then b[i, j][1] := j else
   b[i, j][1] := b[i, j - 1][1];
  end;
  j := 1;
  while a[i, j] = 0 do
  begin
   b[i, j][1] := b[i, m][1];
   inc(j);
  end;
 end;
 for i := 1 to n do
 begin
  j := m;
  while a[i, j] = 0 do dec(j);
  b[i, j][2] := j;
  while j > 1 do
  begin
   dec(j);
   if a[i, j] = 1 then b[i, j][2] := j else
   b[i, j][2] := b[i, j + 1][2];
  end;
  j := m;
  while a[i, j] = 0 do
  begin
   b[i, j][2] := b[i, 1][2];
   dec(j);
  end;
 end;
 ans := n * m + 1;
 for j := 1 to m do
 begin
  k := 0;
  for i := 1 to n do
  begin
   c := j - b[i, j][1];
   if c < 0 then c := c + m;
   d := b[i, j][2] - j;
   if d < 0 then d := d + m;
   k := k + min(c, d);
  end;
  if k < ans then ans := k;
 end;
 writeln(ans);
end.