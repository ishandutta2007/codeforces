program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

var
 n, i, x, cnt: integer;
 a: array[1..4] of integer;

begin
 readln(n);
 fillchar(a, sizeof(a), 0);
 for i := 1 to n do
 begin
  read(x);
  inc(a[x]);
 end;
 cnt := a[4];
 x := a[1];
 if x > a[3] then x := a[3];
 cnt := cnt + x;
 a[1] := a[1] - x;
 a[3] := a[3] - x;
 cnt := cnt + a[3];
 cnt := cnt + a[2] div 2;
 a[2] := a[2] mod 2;
 if a[2] = 1 then
 begin
  if a[1] > 1 then
  begin
   a[2] := 0;
   a[1] := a[1] - 2;
   cnt := cnt + 1;
  end else
  begin
   inc(cnt);
   writeln(cnt);
   halt(0);
  end;
 end;
 cnt := cnt + (a[1] + 3) div 4;
 writeln(cnt);
end.