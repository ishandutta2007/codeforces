var
  n,p,q,s,w,x:int64;
  i:longint;
begin
  readln(n);q:=maxlongint;
  for i:=1 to n do begin
    read(x);
    if x=p then inc(s);
    if x=q then inc(w);
    if x>p then begin
      p:=x;s:=1;
    end;
    if x<q then begin
      q:=x;w:=1;
    end;
  end;
  if p=q then writeln('0 ',s*(s-1) div 2)
  else writeln(p-q,' ',s*w);
end.