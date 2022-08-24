program asdfsdf;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
 n, k, i: integer;
 a: array[1..1000] of byte;

begin
 reset(input,'input.txt');
 rewrite(output,'output.txt');
 readln(n, k);
 for i := 1 to n do
 read(a[i]);
 while a[k] = 0 do
 k := k mod n + 1;
 writeln(k);
end.