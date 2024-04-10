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
 n, m, i, j, s, f, c: integer;
 t, l, r: array[1..100010] of integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, m, s, f);
 for i := 1 to m do read(t[i], l[i], r[i]);
 i := 1;
 j := 1;
 c := s;
 while true do
 begin
  if (t[i] = j) then
  begin
   if (c < f) then
   begin
    if ((c + 1 < l[i]) or (c > r[i])) then
    begin
     inc(c);
     write('R');
    end else
    write('X');
   end else
   begin
    if ((c < l[i]) or (c - 1 > r[i])) then
    begin
     dec(c);
     write('L');
    end else
    write('X');
   end;
   inc(i);
  end else
  begin
   if c < f then
   begin
    c := c + 1;
    write('R');
   end else
   begin
    c := c - 1;
    write('L');
   end;
  end;
  inc(j);
  if c = f then halt(0);
 end;
end.