program qwe;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
 n, x, y: int64;
 i, k: integer;
 boo: boolean;

function sqrtx(x: int64): int64;
var
 a, b: int64;
 vsp: int64;
begin
 a := 1;
 if x > 100000000 then b := x div 1000 else
 b := x;
 while b - a > 1 do
 begin
  vsp := (a + b) div 2;
  vsp := vsp * vsp;
  if vsp > x then
  b := (a + b) div 2 else
  a := (a + b) div 2;
 end;
 result := a;
end;

begin
 readln(n);
 if n = 1 then
 begin
  writeln(1);
  writeln(0);
  halt;
 end;
 i := 2;
 k := 0;
 x := 1;
 y := sqrtx(n);
 boo := false;
 while i <= y do
 begin
  while n mod i = 0 do
  begin
   boo := true;
   n := n div i;
   inc(k);
   if k <= 2 then x := x * i;
   if k >= 3 then
   begin
    writeln(1);
    writeln(x);
    halt;
   end;
  end;
  inc(i);
  if boo then
  begin
   y := sqrtx(n);
   boo := false;
  end;
 end;
 if n > 1 then inc(k);
 if k = 2 then
 begin
  writeln(2);
  halt;
 end;
 if k = 1 then
 begin
  writeln(1);
  writeln(0);
  halt;
 end;
 writeln(1);
 writeln(x);
end.