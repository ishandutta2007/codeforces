

program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}
{$O-}

uses
  SysUtils,
  Math;

//it is a big shablon. if you see any strange function, never mind

const //base = 1000000007;
 eps = 1e-8;
 inf = 1 shl 30;

type
 TArray = array[0..10000010] of integer;
 int53 = int64;
 itneger = integer;
 point = record
  x, y: integer;
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
 base, n, b, i, kol: integer;
 d: array[1..555] of integer;
 flag: boolean;

function pow(a, b: integer): integer;
var
 dega, res: int64;
begin
 res := 1;
 dega := a;
 while b > 0 do begin
  if odd(b) then
  res := (res * dega) mod base;
  dega := (dega * dega) mod base;
  b := b shr 1;
 end;
 result := res mod base;
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 read(n, b);
 if n = 1 then
 begin
  writeln(b - 1);
  halt(0);
 end;
 dec(b);
 inc(n);
 i := 2;
 while i * i <= n do
 begin
  if n mod i = 0 then
  begin
   writeln(-1);
   halt;
  end;
  inc(i);
 end;
 base := n;
 dec(n);
 i := 1;
 kol := 0;
 while (i - 1) * (i - 1) <= n do
 begin
  if n mod i = 0 then
  begin
   inc(kol);
   d[kol] := i;
  end;
  inc(i);
 end;
 for i := 1 to kol do
 d[kol + i] := n div d[kol + 1 - i];
 kol:= kol * 2 - 1;
 flag := false;
 repeat
  if b mod base <> 0 then
  begin
   flag := true;
   for i := 1 to kol do
   flag := flag and (pow(b, d[i]) <> 1);
  end;
  dec(b);
 until ((flag = true) or (b = 0));
 if flag then writeln(b + 1) else
 begin
  writeln(-1);
  halt;
 end;
end.