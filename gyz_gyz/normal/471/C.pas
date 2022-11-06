var
  n,i,x,ans:int64;
begin
  readln(n);
  while i*i<n do begin
    inc(i);
    x:=n-i*(i+1)*3 div 2+i;
    if (x>=0)and(x mod 3=0) then inc(ans);
  end;
  writeln(ans);
end.