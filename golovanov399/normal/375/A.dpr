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

procedure panic;
begin
 writeln(-1);
 halt(0);
end;

var
 s: string;
 i, k, l: integer;
 c: char;
 a: array[0..6] of integer;
 d: array['0'..'9'] of integer;
 q: array[0..6] of integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 a[1986 mod 7] := 1986;
 a[1896 mod 7] := 1896;
 a[1869 mod 7] := 1869;
 a[6189 mod 7] := 6189;
 a[1689 mod 7] := 1689;
 a[6198 mod 7] := 6198;
 a[1698 mod 7] := 1698;
 readln(s);
 fillchar(d, sizeof(d), 0);
 for i := 1 to length(s) do inc(d[s[i]]);
 k := 0;
 l := 1;
 dec(d['1']);
 dec(d['6']);
 dec(d['8']);
 dec(d['9']);
 q[0] := 0;
 q[1] := 1;
 q[2] := 4;
 q[3] := 5;
 q[4] := 2;
 q[5] := 3;
 q[6] := 6;
 for c := '0' to '9' do
 begin
  for i := 1 to d[c] do
  begin
   k := k + l * (ord(c) - ord('0'));
   k := k mod 7;
   l := (l * 10) mod 7;
  end;
 end;
 k := ((7 - k) * q[l]) mod 7;
 write(a[k]);
 for c := '9' downto '0' do
 for i := 1 to d[c] do write(c);
end.