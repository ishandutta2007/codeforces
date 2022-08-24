program qwe;
{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
 s, t: string;
 a: array['a'..'z'] of char;
 st: array[1..100000] of char;
 cc: array[1..100000] of integer;
 k, l, i, cnt, n: integer;
 b: boolean;

begin
 readln(s);
 fillchar(a, sizeof(a), 0);
 readln(k);
 for i := 1 to k do
 begin
  readln(t);
  a[t[1]] := t[2];
  a[t[2]] := t[1];
 end;
 cnt := 0;
 n := 0;
 fillchar(st, sizeof(st), 0);
 fillchar(cc, sizeof(cc), 0);
 i := 1;
 while i <= length(s) do
 begin
  inc(n);
  st[n] := s[i];
  while (i <= length(s)) and (s[i] = st[n]) do
  begin
   inc(cc[n]);
   inc(i);
  end;
 end;
 k := 0;
 l := 0;
 b := false;
 for i := 1 to n - 1 do
 begin
  if a[st[i]] = st[i + 1] then
  begin
   if (k = 0) and (l = 0) then
   k := k + cc[i];
   if b then k := k + cc[i + 1] else l := l + cc[i + 1];
   b := not b;
  end else
  begin
   cnt := cnt + min(k, l);
   k := 0;
   l := 0;
   b := false;
  end;
 end;
 cnt := cnt + min(k, l);
 writeln(cnt);
end.