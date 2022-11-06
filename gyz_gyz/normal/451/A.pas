var
  n,m,min:longint;
begin
  readln(n,m);
  if n>m then min:=m else min:=n;
  if min mod 2=0 then writeln('Malvika') else writeln('Akshat');
end.