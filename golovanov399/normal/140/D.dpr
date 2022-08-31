program qwe123;

{$APPTYPE CONSOLE}

uses
  SysUtils;

procedure swap(var x, y: integer);
var
 z: integer;
begin
 z:=x;
 x:=y;
 y:=z;
end;

var
 n, i, s: integer;
 a, b: array[1..100] of integer;

procedure sort;
var
 i, j: integer;
begin
 for i:=1 to n-1 do
 begin
  for j:=i+1 to n do
  begin
   if a[i] > a[j] then swap(a[i], a[j]);
  end;
 end;
end;

function f(n: integer): integer;
begin
 if n <= 360 then result := 0 else result := n - 360;
end;

begin
// reset(input,'input.txt');
// rewrite(output,'output.txt');
 randomize;
 readln(n);
 for i:=1 to n do
 read(a[i]);
 sort;
 s := 0;
 i := 0;
 while (s + a[i + 1] <= 710) and (i < n) do
 begin
  inc(i);
  s := s + a[i];
 end;
 n := i;
 write(n, ' ');
 if n = 0 then
 begin
  writeln(0);
  halt(0);
 end;
 b[1] := a[1] + 10;
 s := f(b[1]);
 for i:=2 to n do
 begin
  b[i] := b[i - 1] + a[i];
  s := s + f(b[i]);
 end;
{ for i:=1 to 100000 do
 begin
  x := random(n) + 1;
  y := random(n) + 1;
  c := b;
  t := 0;
  w := 0;
  if x > y then swap(x, y);
  for j := x to y - 1 do
  begin
   c[j] := c[j] - a[x] + a[y];
   t := t + f(b[j]);
   w := w + f(c[j]);
  end;
  if w < t then
  begin
   s := s - t + w;
   b := c;
   swap(a[x], a[y]);
  end;
 end;}
 writeln(s);
end.