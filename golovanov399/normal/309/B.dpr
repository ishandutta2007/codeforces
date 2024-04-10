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
 n, r, c, i, j, _, cnt, k: integer;
 a: array[1..1000020] of integer;
 t: array[1..1000020] of string;
 p: array[0..21, 1..1000020] of integer;
 s, tt: string;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input, 'input.txt');
 rewrite(output, 'output.txt');
 {$ENDIF}
 readln(n, r, c);
 readln(s);
 i := 1;
 cnt := 0;
 k := 0;
 tt := '';
 s := s + ' ';
 fillchar(t, sizeof(t), 0);
 while cnt < n do
 begin
  if s[i] = ' ' then
  begin
   if k > 0 then
   begin
    inc(cnt);
    a[cnt] := k;
    t[cnt] := tt;
   end;
   k := 0;
   tt := '';
  end else
  begin
   inc(k);
   tt := tt + s[i];
  end;
  inc(i);
 end;
 a[n + 1] := 2 * c;
 k := 0;
 j := 1;
 for i := 1 to n do
 begin
  while k <= c do
  begin
   if j = i then k := k + a[j] else k := k + a[j] + 1;
   inc(j);
  end;
  dec(j);
  if j = i then k := 0 else k := k - a[j] - 1;
  p[0][i] := j;
  if k = 0 then j := j + 1 else
  if j = i + 1 then k := 0 else
  k := k - a[i] - 1;
 end;
 p[0][n + 1] := n + 1;
 for i := 1 to 20 do
 begin
  for j := 1 to n + 1 do
  p[i][j] := p[i - 1][p[i - 1][j]];
 end;
 for i := 1 to n + 1 do p[21][i] := i;
 k := 1 shl 20;
 _ := r;
 i := 20;
 while _ > 0 do
 begin
  while _ < k do
  begin
   k := k shr 1;
   i := i - 1;
  end;
  for j := 1 to n + 1 do p[21][j] := p[i][p[21][j]];
  _ := _ - k;
 end;
 i := 1;
 for j := 2 to n + 1 do
 if p[21][j] - j > p[21][i] - i then i := j;
 while ((i <= n) and (r > 0)) do
 begin
  k := -1;
  while ((i <= n) and (k + a[i] + 1 <= c)) do
  begin
   if k = -1 then write(t[i]) else write(' ', t[i]);
   k := k + a[i] + 1;
   inc(i);
  end;
  writeln;
  dec(r);
 end;
end.