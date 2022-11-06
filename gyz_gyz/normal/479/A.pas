var a,b,c:int64;
begin
  readln(a,b,c);
  if a=1 then
    if c=1 then writeln(a+b+c)
    else writeln((a+b)*c)
  else
    if b>1 then
      if c>1 then writeln(a*b*c)
      else writeln(a*(b+c))
    else
      if a>c then writeln(a*(b+c))
      else writeln((a+b)*c)
end.