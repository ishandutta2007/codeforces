program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

const base = 1000000007;
 eps = 1e-8;

type
 TArray = array[0..1000010] of integer;
 int53 = int64;
 itneger = integer;
 point = record
  x, y: integer;
 end;
 
function sqrr(a, b: integer): int64;
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

(*
procedure QSort(l, r: integer);
var
 i, j, x: integer;
begin
 if l >= r then exit;
 i := l;
 j := r;
 x := l + random(r - l + 1);
 repeat
  while (m[i] > m[x]) or ((m[i] = m[x]) and (v[i] > v[x])) do inc(i);
  while (m[j] < m[x]) or ((m[j] = m[x]) and (v[j] < v[x])) do dec(j);
  if i <= j then
  begin
   swap(m[i], m[j]);
   swap(v[i], v[j]);
   swap(num[i], num[j]);
   inc(i);
   dec(j);
  end;
 until i > j;
 QSort(l, j);
 QSort(i, r);
end;
*)

procedure panic;
begin
 writeln(-1);
 halt(0);
end;

var
 n, m, i, j, _: integer;
 s: string;
 a, b: array[1..1000] of integer;
 ar: array[1..1000, 1..1000] of boolean;
 dt, ddt: array[1..1000] of integer;
 cnt, ct: integer;
 hh: array[1..1000] of integer;
 p: integer;

begin
 readln(n, m);
 p := 0;
 for i := 1 to n do
 begin
  readln(s);
  for j := 1 to m do
  if s[j] = '#' then
  ar[i, j] := true else
  ar[i, j] := false;
 end;
 cnt := 0;
 for i := 1 to n do a[i] := -1;
 for i := 1 to m do b[i] := -1;
 a[1] := 0;
 for i := 1 to m do
 if ar[1, i] then
 begin
  inc(cnt);
  dt[cnt] := i;
 end;
 _ := 1;
 while cnt <> 0 do
 begin
  if odd(_) then
  begin
   ct := 0;
   inc(p);
   for i := 1 to cnt do
   begin
    for j := 1 to n do
    if (ar[j, dt[i]]) and (hh[j] < p) and (a[j] = -1) then
    begin
     hh[j] := p;
     inc(ct);
     ddt[ct] := j;
     a[j] := _;
    end;
   end;
   cnt := ct;
   for i := 1 to cnt do dt[i] := ddt[i];
  end else
  begin
   ct := 0;
   inc(p);
   for i := 1 to cnt do
   begin
    for j := 1 to m do
    if (ar[dt[i], j]) and (hh[j] < p) and (b[j] = -1) then
    begin
     hh[j] := p;
     inc(ct);
     ddt[ct] := j;
     b[j] := _;
    end;
   end;
   cnt := ct;
   for i := 1 to cnt do dt[i] := ddt[i];
  end;
  if a[n] <> -1 then
  begin
   writeln(_ + 1);
   halt(0);
  end;
  inc(_);
 end;
 panic;
end.