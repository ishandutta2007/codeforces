var
  n,m:longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
function min(x,y:longint):longint;
begin
  if x>y then exit(y) else exit(x);
end;
begin
  readln(n,m);
  writeln(max(n,m)-1,' ',min(n,m))
end.