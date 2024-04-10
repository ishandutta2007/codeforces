var
  a,b,c,d,e:int64;
begin
  readln(a,b,c,d,e);
  if (a+b+c+d+e>0)and((a+b+c+d+e) mod 5=0) then writeln((a+b+c+d+e) div 5) else writeln(-1);
end.