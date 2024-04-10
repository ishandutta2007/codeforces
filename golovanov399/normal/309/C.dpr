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
 n, m, i, j, _, k: integer;
 a, b: array[1..1000000] of itneger;
 c, d: array[0..31] of integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m);
 for i := 1 to n do read(a[i]);
 for i := 1 to m do read(b[i]);
 fillchar(c, sizeof(c), 0);
 d[0] := 1;
 for i := 1 to 30 do d[i] := d[i - 1] * 2;
 for i := 30 downto 0 do
 begin
  for j := 1 to n do
  if a[j] >= d[i] then
  begin
   inc(c[i]);
   a[j] := a[j] - d[i];
  end;
 end;
 k := 0;
 for i := 0 to 30 do
 begin
  for j := 1 to m do
  if b[j] = i then
  begin
   _ := i;
   while ((_ < 31) and (c[_] = 0)) do inc(_);
   if c[_] > 0 then
   begin
    inc(k);
    dec(c[_]);
    while _ > i do
    begin
     dec(_);
     inc(c[_]);
    end;
   end;
  end;
 end;
 writeln(k);
end.