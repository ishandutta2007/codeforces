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

var
 s: string;
 i, j, a, b: integer;
 n: integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(s);
 n := length(s);
 i := 1;
 while ((i < length(s)) and ((s[i] = '4') or (s[i] = '7'))) do inc(i);
 for j := i + 1 to n do s[j] := '4';
 while ((i >= 1) and (s[i] <> '4') and (s[i] <> '7')) do
 begin
  if s[i] < '4' then s[i] := '4' else
  if s[i] < '7' then s[i] := '7' else
  begin
   s[i] := '4';
   dec(i);
   if i >= 1 then s[i] := chr(ord(s[i]) + 1);
  end;
 end;
 if i = 0 then s := '4' + s;
 n := length(s);
 if odd(n) then
 begin
  for i := 1 to (n + 1) div 2 do write('4');
  for i := 1 to (n + 1) div 2 do write('7');
  halt(0);
 end;
 a := 0;
 b := 0;
 for i := 1 to n do if s[i] = '4' then inc(a) else inc(b);
 if a = b then
 writeln(s) else
 if a > b then
 begin
  a := (a - b) div 2;
  i := n;
  while a > 0 do
  begin
   while s[i] = '7' do dec(i);
   s[i] := '7';
   dec(a);
  end;
  writeln(s);
 end else
 begin
  b := 0;
  a := 0;
  i := 0;
  while ((i < n) and (b < n div 2)) do
  begin
   inc(i);
   if s[i] = '7' then inc(a) else
   begin
    b := b + a;
    a := 0;
   end;
  end;
  dec(i);
  while ((i >= 1) and (s[i] = '7')) do dec(i);
  if i = 0 then
  begin
   for i := 1 to n div 2 + 1 do write(4);
   for i := 1 to n div 2 + 1 do write(7);
  end else
  begin
   s[i] := '7';
   for j := i + 1 to n do s[j] := '4';
   b := 0;
   for i := 1 to n do if s[i] = '7' then inc(b);
   for i := 1 to n div 2 - b do s[n + 1 - i] := '7';
   writeln(s);
  end;
 end;
end.