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

var
 n, m, i, x, y: itneger;
 data, data1, next, next1: array[0..1000000] of integer;
 first, first1: array[0..100010] of integer;
 free, free1: integer;
 was, were: array[1..100000] of boolean;
 st: array[1..100000] of byte;

procedure add(x, y: integer);
begin
 next[free] := first[x];
 first[x] := free;
 data[free] := y;
 inc(free);
end;

procedure add1(x, y: integer);
begin
 next1[free1] := first1[x];
 first1[x] := free1;
 data1[free1] := y;
 inc(free1);
end;

procedure dfs(v, x: integer);
var
 i: integer;
begin
 if (was[v]) or ((st[v] = 1) and (x > 0)) then exit;
 was[v] := true;
 if st[v] = 1 then inc(x);
 i := first[v];
 while i > 0 do
 begin
  dfs(data[i], x);
  i := next[i];
 end;
end;

procedure dfs1(v: integer);
var
 i: integer;
begin
 if (were[v]) then exit;
 were[v] := true;
 if st[v] = 1 then exit;
 i := first1[v];
 while i > 0 do
 begin
  dfs1(data1[i]);
  i := next1[i];
 end;
end;

begin
 free := 1;
 free1 := 1;
 readln(n, m);
 for i := 1 to n do
 read(st[i]);
 for i := 1 to m do
 begin
  readln(x, y);
  add(x, y);
  add1(y, x);
 end;
 fillchar(was, sizeof(was), 0);
 fillchar(were, sizeof(were), 0);
 for i := 1 to n do
 if st[i] = 1 then dfs(i, 0) else
 if st[i] = 2 then dfs1(i);
 for i := 1 to n do
 if (was[i]) and (were[i]) then writeln(1) else writeln(0);
end.