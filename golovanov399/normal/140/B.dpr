program qwe123;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
 n, i, j, l: integer;
 a: array[1..300, 1..300] of integer;
 b: array[1..300] of integer;
 boo, bb: boolean;

begin
// reset(input,'input.txt');
// rewrite(output,'output.txt');
 readln(n);
 for i := 1 to n do
 begin
  for j := 1 to n do
  read(a[i, j]);
 end;
 for i := 1 to n do
 read(b[i]);
 for i := 1 to n do
 begin
  j:=0;
  boo := false;
  while not boo do
  begin
   inc(j);
   l := 1;
   bb := false;
   while b[l] <> a[i, j] do
   begin
    if (b[l] < a[i, j])and(b[l] <> i) then bb := true;
    inc(l);
   end;
   if a[i, j] <> i then
   boo := not bb;
  end;
  write(a[i, j], ' ');
 end;
end.