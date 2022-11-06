var
  a,b,c,d,e,f:extended;
begin
  readln(a,b,c,d,e,f);
  if d=0 then begin writeln('Hermione');halt;end;
  if c=0 then begin writeln('Ron');halt;end;
  if b=0 then begin writeln('Hermione');halt;end;
  if a=0 then begin writeln('Ron');halt;end;
  if f=0 then begin writeln('Hermione');halt;end;
  if e=0 then begin writeln('Ron');halt;end;
  if b/a*d/c*f/e>1 then writeln('Ron') else writeln('Hermione');
end.