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
 writeln('Error occurred');
 halt(0);
end;

var
 s, t: string;
 n, i, m: integer;
 a: array[0..100010] of integer;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n);
 readln(s);
 fillchar(a, sizeof(a), 0);
 i := 1;
 t := '';
 m := 0;
 a[0] := 1;
 while i <= length(s) do
 begin
  if s[i] = 'i' then
  begin
   t := t + 'int';
   i := i + 4;
   inc(a[m]);
   while (m >= 0) and (a[m] = 2) do
   begin
    dec(m);
    if m >= 0 then
    begin
     inc(a[m]);
     t := t + '>';
    end;
   end;
   if m >= 0 then t := t + ',' else
   if i <= length(s) then panic;
  end else
  begin
   i := i + 5;
   inc(m);
   t := t + 'pair<';
   a[m] := 0;
  end;
 end;
 if m >= 0 then panic else
 writeln(t);
end.