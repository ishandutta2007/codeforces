const x:array[1..15]of char=('B','C','D','E','F','G','J','K','L','N','P','Q','R','S','Z');
var
  s:ansistring;
  i,j:longint;
begin
  readln(s);
  for i:=1 to length(s) do
    for j:=1 to 15 do
      if s[i]=x[j] then begin
        writeln('NO');exit;
      end;
  for i:=1 to length(s) div 2 do
    if s[i]<>s[length(s)-i+1] then begin
      writeln('NO');exit;
    end;
  writeln('YES');
end.