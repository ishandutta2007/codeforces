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
 n, m: int64;
 s, t: string;
 x, y, d, xx, yy, i, j: integer;
 ans, v: int64;
 a, b: array['a'..'z'] of integer;
 c: char;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m);
 readln(s);
 readln(t);
 xx := length(s);
 yy := length(t);
 x := xx;
 y := yy;
 while ((xx > 0) and (yy > 0)) do
 begin
  if xx > yy then xx := xx mod yy else yy := yy mod xx;
 end;
 d := xx + yy;
 fillchar(a, sizeof(a), 0);
 ans := 0;
 for i := 1 to d do
 begin
  for c := 'a' to 'z' do a[c] := 0;
  for j := 1 to (x div d) do inc(a[s[(j - 1) * d + i]]);
  for c := 'a' to 'z' do b[c] := 0;
  for j := 1 to (y div d) do inc(b[t[(j - 1) * d + i]]);
  for c := 'a' to 'z' do
  begin
   v := a[c];
   v := v * b[c];
   ans := ans + v;
  end;
 end;
 v := n;
 v := v * d;
 v := v div y;
 ans := ans * v;
 m := m * y;
 writeln(m - ans);
end.