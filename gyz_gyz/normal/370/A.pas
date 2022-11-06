var
  x1,y1,x2,y2,ans:longint;
begin
  readln(x1,y1,x2,y2);ans:=2;
  if x1=x2 then dec(ans);
  if y1=y2 then dec(ans);
  write(ans,' ');ans:=2;
  if x1-y1=x2-y2 then dec(ans);
  if x1+y1=x2+y2 then dec(ans);
  if (x1-y1-x2+y2) mod 2<>0 then ans:=0;
  if (x1+y1-x2-y2) mod 2<>0 then ans:=0;
  write(ans,' ');
  if abs(x1-x2)>abs(y1-y2) then writeln(abs(x1-x2)) else writeln(abs(y1-y2));
end.