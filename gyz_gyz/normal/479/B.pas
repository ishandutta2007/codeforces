var
  a,f,r:array[1..1000]of longint;
  n,m,i,j,mx,mi,ans:longint;
begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do begin
    mx:=1;mi:=1;
    for j:=2 to n do begin
      if a[j]>a[mx] then mx:=j;
      if a[j]<a[mi] then mi:=j;
    end;
    if a[mx]-a[mi]>1 then begin
      f[i]:=mx;r[i]:=mi;
      dec(a[mx]);inc(a[mi]);inc(ans);
    end else break;
  end;
  mx:=1;mi:=1;
  for j:=2 to n do begin
    if a[j]>a[mx] then mx:=j;
    if a[j]<a[mi] then mi:=j;
  end;
  writeln(a[mx]-a[mi],' ',ans);
  while ans>0 do begin
    writeln(f[ans],' ',r[ans]);dec(ans);
  end;
end.