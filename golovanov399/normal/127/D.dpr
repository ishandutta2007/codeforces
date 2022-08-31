program kmp;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
 a: array[1..1000000] of integer;
 s: string;
 i, k, n, m: integer;
 b: array[1..1000000] of boolean;

begin
 readln(s);
 n:=length(s);
 fillchar(a, sizeof(a), 0);
 a[1]:=0;
 i:=2;
 while i<=n do
 begin
  k:=a[i-1];
  while (k>0)and(s[i]<>s[k+1]) do
  k:=a[k];
  if s[k+1] = s[i] then a[i]:=k+1 else
  a[i]:=0;
  inc(i);
 end;
 k:=a[n];
 fillchar(b, sizeof(b), 0);
 while k>0 do
 begin
  b[k]:=true;
  k:=a[k];
 end;
 m:=0;
 for i:=2 to n-1 do
 begin
  if (a[i]>0) and (b[a[i]]) and (a[i]>m) then
  m:=a[i];
 end;
 if m = 0 then
 writeln('Just a legend') else
 writeln(copy(s, 1, m));
end.