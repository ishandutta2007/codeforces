var
  a,b:array[0..1000]of boolean;
  n,m,l,r,i,j,x,y,ans:longint;
begin
  readln(n,m,l,r);
  for i:=1 to n do begin
    readln(x,y);
    for j:=x to y do a[j]:=true;
  end;
  for i:=1 to m do begin
    readln(x,y);
    for j:=x to y do b[j]:=true;
  end;
  for i:=l to r do
    for j:=i to 1000 do
      if (a[j])and(b[j-i]) then begin
        inc(ans);break;
      end;
  writeln(ans);
end.