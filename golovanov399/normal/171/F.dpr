var
 n, i, k: integer;

function prost(x: integer): boolean;
var
 i: integer;
begin
 i := 2;
 result := false;
 while i <= sqrt(x) do
 begin
  if x mod i = 0 then exit;
  inc(i);
 end;
 result := true;
end;

function lol(x: integer): integer;
begin
 result := 0;
 while x > 0 do
 begin
  result := result * 10 + x mod 10;
  x := x div 10;
 end;
end;

begin
 i := 11;
 k := 10;
 readln(n);
 while n > 0 do
 begin
  repeat
   inc(i, 2);
   if i div k > 9 then k := k * 10;
   if ((i div k) mod 2 = 0) or ((i div k) mod 10 = 5) then i := i + k - (i mod k) + 1;
  until (prost(i)) and (prost(lol(i))) and (i <> lol(i));
  dec(n);
 end;
 writeln(i);
end.