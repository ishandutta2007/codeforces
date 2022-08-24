program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

var
 n, i, j, x: integer;
 a, m: array[0..20000] of integer;

begin
 readln(n);
 x := 0;
 for i := 1 to n do
 begin
  read(a[i]);
  x := x + a[i];
 end;
 for i := 2 to (n + 1) div 2 - 1 do
 begin
  if n mod i = 0 then
  begin
   fillchar(m, sizeof(m), 0);
   for j := 1 to n do
   m[j mod i] := m[j mod i] + a[j];
   for j := 0 to i - 1 do
   if x < m[j] then x := m[j];
  end;
 end;
 writeln(x);
end.