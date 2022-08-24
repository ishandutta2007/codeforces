program qwe;
{don't read my code, enemy}
{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const base = 1000000007;

function sqrr(a, b: integer): integer;
var
 dega: int64;
 res: int64;
begin
 dega := a;
 res := 1;
 while b > 0 do
 begin
  if odd(b) then res := (res * dega) mod base;
  dega := (dega * dega) mod base;
  b := b div 2;
 end;
 result := res mod base;
end;

var
 n, m, k: integer;

begin
 readln(n, m, k);
 if (k > n) or (k = 1) then writeln(sqrr(m, n)) else
 if k = n then writeln(sqrr(m, (n + 1) div 2)) else
 if k mod 2 = 0 then writeln(m) else
 writeln(sqrr(m, 2));
end.