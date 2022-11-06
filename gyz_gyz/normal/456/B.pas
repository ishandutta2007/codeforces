var
  s:ansistring;
  n,x:longint;
begin
  readln(s);
  n:=length(s);
  if n=1 then x:=ord(s[n])-48
  else x:=ord(s[n-1])*10+ord(s[n])-528;
  if x and 3=0 then writeln(4) else writeln(0);
end.