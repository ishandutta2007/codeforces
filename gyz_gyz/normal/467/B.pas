var
  a:array[1..1000]of longint;
  n,m,k,i,x,p,s,ans:longint;
begin
  readln(n,m,k);
  for i:=1 to m do readln(a[i]);
  readln(p);
  for i:=1 to m do begin
    x:=p xor a[i];s:=0;
    while x>0 do begin
      if x and 1=1 then inc(s);
      x:=x shr 1;
    end;
    if s<=k then inc(ans);
  end;
  writeln(ans);
end.