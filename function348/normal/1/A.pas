var
 a,b,c:int64;
begin
  readln(a,b,c);
  a:=(a-1)div c+1;
  b:=(b-1)div c+1;
  writeln(a*b);
end.