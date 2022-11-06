var n,i,x,y,ans:longint;
begin
  readln(n);
  for i:=1 to n do begin
    y:=x;read(x);
    if x=1 then begin
      inc(ans);
      if y=0 then inc(ans);
    end;
  end;
  if ans<1 then writeln(0)
  else writeln(ans-1);
end.