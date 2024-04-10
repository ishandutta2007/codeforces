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
 trye = true;

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

function gcd(x, y: integer): integer;
begin
 while ((x > 0) and (y > 0)) do
 begin
  if x > y then x := x mod y else y := y mod x;
 end;
 result := x + y;
end;

function nok(x, y: integer): int64;
var
 v: int64;
begin
 v := x;
 v := v * y;
 v := v div gcd(x, y);
 result := v;
end;

var
 a: integer;
 s: string;
 i, j: integer;
 d: array[0..40000] of integer;
 ar: array[0..40000] of integer;
 ans, v: int64;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(a);
 readln(s);
 fillchar(ar, sizeof(ar), 0);
 d[0] := 0;
 for i := 1 to length(s) do
 begin
  d[i] := d[i - 1] + ord(s[i]) - ord('0');
 end;
 for i := 0 to length(s) do
 for j := i + 1 to length(s) do
 inc(ar[d[j] - d[i]]);
 ans := 0;
 if a = 0 then
 begin
  ans := length(s);
  ans := ans * (length(s) + 1);
  ans := ans div 2;
  ans := ans * ar[0];
  ans := ans * 2;
  v := ar[0];
  v := v * v;
  ans := ans - v;
 end else
 begin
  for i := 1 to 40000 do
  if (a mod i = 0) then
  begin
   v := ar[i];
   if (a div i <= 40000) then
   v := v * ar[a div i] else v := 0;
   ans := ans + v;
  end;
 end;
 writeln(ans);
end.