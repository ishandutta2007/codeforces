program qwe;
{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $00200000}

uses
  SysUtils,
  Math;

var
 s: string;
 c: char;
 k, i, n, j, x, y: integer;
 cnt: array['a'..'z'] of integer;
 kol: array['a'..'z', 1..2000] of integer;
 a: array[1..2000] of string;

begin
 fillchar(cnt, sizeof(cnt), 0);
 fillchar(a, sizeof(a), 0);
 fillchar(kol, sizeof(kol), 0);
 readln(k);
 readln(s);
 for i := 1 to length(s) do
 inc(cnt[s[i]]);
 for i := 1 to k do a[i] := s;
 for i := 1 to k do
 for c := 'a' to 'z' do
 kol[c, i] := cnt[c];
 readln(n);
 for i := 1 to n do
 begin
  readln(s);
  x := strtoint(copy(s, 1, pos(' ', s) - 1));
  delete(s, 1, pos(' ', s));
  j := 1;
  y := 0;
  while y + kol[s[1], j] < x do
  begin
   y := y + kol[s[1], j];
   inc(j);
  end;
  x := x - y;
  y := 0;
  while x > 0 do
  begin
   dec(x);
   repeat
    inc(y);
   until a[j][y] = s[1];
  end;
  dec(kol[s[1], j]);
  delete(a[j], y, 1);
 end;
 for i := 1 to k do write(a[i]);
end.