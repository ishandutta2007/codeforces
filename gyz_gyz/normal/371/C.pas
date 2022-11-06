var
  a1,a2,a3,b1,b2,b3,c1,c2,c3,n,l,r,m:int64;
  i:longint;
  s:string;
function p(x:int64):int64;inline;
begin
  if x>0 then exit(x) else exit(0);
end;
begin
  readln(s);
  for i:=1 to length(s) do
    case s[i] of
      'B':inc(a1);
      'S':inc(a2);
      'C':inc(a3);
    end;
  readln(b1,b2,b3);
  readln(c1,c2,c3);
  readln(n);
  l:=0;r:=trunc(10e13);
  m:=(l+r) shr 1;
  while l+1<r do begin
    if p(m*a1-b1)*c1+p(m*a2-b2)*c2+p(m*a3-b3)*c3<=n then l:=m else r:=m;
    m:=(l+r) shr 1;
  end;
  writeln(m);
end.