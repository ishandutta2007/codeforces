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
 s, t: string;
 b: array[0..1010] of boolean;
 i, j, n, k: integer;
 x, y, xx, yy, ans: int64;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input,'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(s);
 readln(t);
 n := length(s);
 for i := 1 to n do
 begin
  b[i - 1] := true;
  for j := 0 to n - 1 do
  b[i - 1] := b[i - 1] and (s[j + 1] = t[(i + j - 1) mod n + 1]);
 end;
 readln(k);
 ans := 0;
 if k = 0 then
 begin
  if s = t then
  writeln(1) else
  writeln(0);
  halt(0);
 end else
 if k = 1 then
 begin
  for i := 2 to n do
  if b[i - 1] then inc(ans);
  writeln(ans);
  halt(0);
 end;
 if n = 2 then
 begin
  if (s = t) and (s[1] = s[2]) then writeln(1) else
  if s = t then writeln(1 - k mod 2) else
  if (s[1] = t[2]) and (s[2] = t[1]) then writeln(k mod 2) else
  writeln(0);
  halt(0);
 end;
 dec(k, 2);
 x := n - 1;
 y := n - 2;
 for i := 1 to k do
 begin
  xx := y * (n - 1) mod base;
  yy := y * (n - 2) mod base;
  yy := (yy + x) mod base;
  x := xx;
  y := yy;
 end;
 for i := 1 to n - 1 do
 if b[i] then ans := (ans + y) mod base;
 if b[0] then ans := (ans + x) mod base;
 writeln(ans); 
end.