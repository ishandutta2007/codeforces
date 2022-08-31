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

var
 i, k: integer;
 s, t: string;
 fl: boolean;

begin
 readln(s);
 k := 0;
 fl := false;
 for i := 1 to length(s) do
 if s[i] <> '.' then
 begin
  inc(k);
  if ((not fl) and (k > 8)) or (k > 11) then
  begin
   writeln('NO');
   halt(0);
  end;
 end else
 begin
  if (k < 1) or ((fl) and (k < 2)) then
  begin
   writeln('NO');
   halt(0);
  end;
  fl := true;
  k := 0;
 end;
 if (not fl) or (k > 3) or (k = 0) then
 begin
  writeln('NO');
  halt(0);
 end;
 writeln('YES');
 write(copy(s, 1, pos('.', s) - 1));
 i := pos('.', s);
 inc(i);
 t := '';
 while i <= length(s) do
 begin
  while (i <= length(s)) and (s[i] <> '.') do
  begin
   t := t + s[i];
   inc(i);
  end;
  if i > length(s) then writeln('.', t) else
  begin
   if length(t) = 2 then
   begin
    writeln('.', t[1]);
    write(t[2]);
   end else
   if length(t) = 3 then
   begin
    writeln('.', t[1]);
    write(t[2], t[3]);
   end else
   begin
    writeln('.', copy(t, 1, 3));
    write(copy(t, 4, length(t) - 3));
   end;
  end;
  inc(i);
  t := '';
 end;
end.