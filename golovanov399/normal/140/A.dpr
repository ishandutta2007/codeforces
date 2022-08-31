program qwe123;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;

type
 extended = double;

const
 eps = 0.000000001;

var
 n, r, rr, s: integer;
 alpha: extended;

begin
// reset(input,'input.txt');
// rewrite(output,'output.txt');
 readln(n, rr, r);
 s := rr - r;
 if (s < 0) then
 begin
  writeln('NO');
  halt(0);
 end;
 if (s < r) then
 begin
  if n = 1 then
  writeln('YES') else
  writeln('NO');
  halt(0);
 end;
 alpha := arccos(1 - 2*r*r/(s*s));
 if alpha * n <= 2 * pi + eps then writeln('YES') else writeln('NO'); 
end.