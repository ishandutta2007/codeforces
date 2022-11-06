const mx:int64=1000000007;
var
  a,b,s,p,ans:int64;
  i:longint;
begin
  readln(a,b);p:=1;
  for i:=1 to a do begin
    p:=p+b;
    if p>mx then dec(p,mx);
    s:=s+p;
    if s>mx then dec(s,mx);
  end;
  p:=0;
  for i:=1 to b-1 do begin
    p:=p+s;
    if p>mx then dec(p,mx);
    ans:=ans+p;
    if ans>mx then dec(ans,mx);
  end;
  writeln(ans);
end.