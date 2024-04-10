program qwe;
{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
 n, m, i, k, cnt: integer;
 x, y, z: array[1..100000] of integer;
 b: array[1..100000] of boolean;
 data: array[1..100000] of integer;

begin
 fillchar(x, sizeof(x), 0);
 fillchar(y, sizeof(y), 0);
 fillchar(z, sizeof(z), 0);
 readln(n, m);
 for i := 1 to n do
 begin
  readln(data[i]);
  if data[i] > 0 then
  inc(x[data[i]]) else
  inc(y[-data[i]]);
 end;
 k := 0;
 for i := 1 to n do
 begin
  z[i] := x[i] - y[i];
  k := k + y[i];
 end;
 fillchar(b, sizeof(b), 0);
 cnt := 0;
 for i := 1 to n do
 if k + z[i] = m then
 begin
  inc(cnt);
  b[i] := true;
 end;
 for i := 1 to n do
 begin
  if data[i] > 0 then
  begin
   if not b[data[i]] then writeln('Lie') else
   if cnt > 1 then writeln('Not defined') else
   writeln('Truth');
  end else
  begin
   if not b[-data[i]] then writeln('Truth') else
   if cnt > 1 then writeln('Not defined') else
   writeln('Lie');
  end;
 end;
end.