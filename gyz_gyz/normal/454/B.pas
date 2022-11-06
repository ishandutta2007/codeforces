var n,i,x,y,ans,p:longint;
begin
  readln(n);
  read(p);x:=p;
  for i:=2 to n do begin
    read(y);
    if (y<x)and(ans<>0) then begin
      writeln(-1);exit;
    end;
    if y<x then ans:=n-i+1;
    x:=y;
  end;
  if (x>p)and(ans<>0) then writeln(-1) else writeln(ans);
end.