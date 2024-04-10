var n,m,k,l: longint;
begin
  readln (n,m,k);
  while k>0 do
  begin
    if (n>1) and (m>1) then l:=2*(n-2)+2*m+l else
    if n=1 then l:=l+n else l:=l+m;
    n:=n-4;
    m:=m-4;
    k:=k-1;
  end;
  writeln (l);
end.