var a,b,c,x,y,z: longint;

begin
  readln (x,y,z);
  readln (a,b,c);
  a:=a-x;
  if (a>=0) and ((a+b)>=y) and (a+b+c>=y+z) then writeln ('YES') else writeln ('NO');
end.