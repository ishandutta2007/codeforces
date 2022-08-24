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

var
 n, i, j, ans: integer;
 a: array[-1000..1000, -1000..1000] of boolean;
 b: array[1..3000] of point;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input,'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n);
 for i := 1 to n do
 begin
  readln(b[i].x, b[i].y);
  a[b[i].x, b[i].y] := true;
 end;
 ans := 0;
 for i := 1 to n - 1 do
 for j := i + 1 to n do
 if ((b[i].x + b[j].x) mod 2 = 0) and ((b[i].y + b[j].y) mod 2 = 0) and (a[(b[i].x + b[j].x) div 2, (b[i].y + b[j].y) div 2]) then inc(ans);
 writeln(ans);
end.