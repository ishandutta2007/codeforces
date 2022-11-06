var n:longint;
begin
  readln(n);
  if n and 3=0 then writeln(n>>1,' ',n>>1) else
    if n and 1=0 then writeln(n>>1-1,' ',n>>1+1) else
      if n>18 then writeln('9 ',n-9) else writeln(n-9,' 9');
end.