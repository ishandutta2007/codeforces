var
  x1,y1,x2,y2:longint;
begin
  readln(x1,y1,x2,y2);
  if x1=x2 then writeln(x1+y1-y2,' ',y1,' ',x1+y1-y2,' ',y2)
  else if y1=y2 then writeln(x1,' ',y1+x1-x2,' ',x2,' ',y1+x1-x2)
  else if abs(x1-x2)=abs(y1-y2) then writeln(x1,' ',y2,' ',x2,' ',y1)
  else writeln(-1);
end.