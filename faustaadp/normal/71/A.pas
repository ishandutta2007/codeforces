program longword;
var
n:longint;
i:longint;
s:array[1..100] of string;

begin
readln(n);
 for i:=1 to n do begin
  readln(s[i]);
 end;

 for i:=1 to n do begin
  if length(s[i])>10 then
   writeln(s[i][1],length(s[i])-2,s[i][length(s[i])])
  else
   writeln(s[i]);
 end;
end.