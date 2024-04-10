program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

var
 n, k, i: integer;
 a: array[1..50] of integer;

begin
 readln(n, k);
 for i := 1 to n do
 read(a[i]);
 i := k;
 if a[i] > 0 then
 begin
  while (i < n) and (a[i] = a[i + 1]) do
  inc(i);
 end else
 begin
  while (i > 0) and (a[i] <= 0) do
  dec(i);
 end;
 writeln(i);
end.