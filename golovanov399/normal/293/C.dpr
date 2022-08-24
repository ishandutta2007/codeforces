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
 writeln(-1);
 halt(0);
end;

var
 n, m: int64;
 ans, v: int64;
 i, j, _: integer;
 cnt, cc: integer;
 a: array[1..30000000] of int64;
 p: array[1..10000] of int64;
 c: array[1..10000] of integer;

procedure QSort(l, r: integer);
var
 i, j: integer;
 x: int64;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := a[l + random(r - l + 1)];
 repeat
  while a[i] < x do inc(i);
  while a[j] > x do dec(j);
  if i <= j then
  begin
   swap64(a[i], a[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort(l, j);
 QSort(i, r);
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n);
 if n mod 3 <> 0 then writeln(0) else
 begin
  n := n div 3;
  ans := 0;

  m := n;
  cc := 0;
  i := 2;
  while i <= sqrt(m + eps) + 1 do
  begin
   if m mod i = 0 then
   begin
    inc(cc);
    p[cc] := i;
    c[cc] := 0;
    while m mod i = 0 do
    begin
     m := m div i;
     inc(c[cc]);
    end;
   end;
   inc(i);
  end;
  if m > 1 then
  begin
   inc(cc);
   p[cc] := m;
   c[cc] := 1;
  end;

  cnt := 1;
  a[cnt] := 1;
  for i := 1 to cc do
  begin
   v := 1;
   for j := 1 to c[i] do
   begin
    v := v * p[i];
    for _ := 1 to cnt do
    a[_ + j * cnt] := a[_] * v;
   end;
   cnt := cnt * (c[i] + 1);
  end;

  randomize;
  QSort(1, cnt);
{
  i := 1;
  while i <= sqrt(n + eps) + 1 do
  begin
   if n mod i = 0 then
   begin
    inc(cnt);
    a[cnt] := i;
   end;
   inc(i);
  end;

  if a[cnt] * a[cnt] <> n then
  begin
   for i := cnt downto 1 do
   a[cnt + cnt - i + 1] := n div a[i];
   cnt := cnt + cnt;
  end else
  begin
   for i := cnt - 1 downto 1 do
   a[cnt + cnt - i] := n div a[i];
   cnt := cnt + cnt - 1;
  end;
}

  for i := 1 to (cnt div 2) + 1 do
  begin
   j := i;
   while ((j <= cnt) and (a[i] * a[j] <= n) and (a[j] <= n / a[i] / a[j] + 1)) do
   begin
    if n mod (a[i] * a[j]) = 0 then
    begin
     v := (n div a[i]) div a[j];
     if ((a[i] <= a[j]) and (a[j] <= v) and ((a[i] + a[j] + v) mod 2 = 0) and (a[i] + a[j] > v) and (a[i] + v > a[j]) and (a[j] + v > a[i])) then
     begin
      if ((a[i] = a[j]) and (a[j] = v)) then ans := ans + 1 else
      if ((a[i] = a[j]) or (a[j] = v) or (a[i] = v)) then ans := ans + 3 else
      ans := ans + 6;
     end;
    end;
    inc(j);
   end;
  end;
  writeln(ans);
 end;
end.