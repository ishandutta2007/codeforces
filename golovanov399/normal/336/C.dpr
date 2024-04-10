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
 a: array[1..100000] of integer;
 b: array[0..30, 1..100000] of boolean;
 d, s, cnt: array[0..30] of integer;
 i, j, k, n: integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n);
 d[0] := 1;
 fillchar(cnt, sizeof(Cnt), 0);
 for i := 1 to 30 do d[i] := d[i - 1] * 2;
 for i := 1 to n do
 begin
  read(a[i]);
  for j := 0 to 30 do
  if (a[i] and d[j] > 0) then
  begin
   b[j, i] := true;
   inc(cnt[j]);
  end else b[j, i] := false;
 end;
 for j := 0 to 30 do
 begin
  k := d[30] - 1;
  for i := 1 to n do
  if b[j, i] then k := k and a[i];
  s[j] := 0;
  while k mod 2 = 0 do
  begin
   k := k div 2;
   inc(s[j]);
  end;
 end;
 i := 0;
 for j := 1 to 30 do if ((s[j] > s[i]) or ((s[j] = s[i]) and (cnt[j] > cnt[i]))) then i := j;
 j := i;
 k := 0;
 for i := 1 to n do
 if b[j, i] then inc(k);
 writeln(k);
 for i := 1 to n do
 if b[j, i] then write(a[i], ' ');
end.