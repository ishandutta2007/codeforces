var w,h,u1,i,d1,u2,d2: longint;

begin
  readln (w,h);
  readln (u1,d1);
  readln (u2,d2);
  for i:=h downto 1 do
  begin
    w:=w+i;
    if i=d1 then w:=max(0,w-u1);
    if i=d2 then w:=max(0,w-u2);
  end;
  writeln (w);
end.