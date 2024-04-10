var
  a:array[0..9,0..100000]of longint;
  n,m,k,i,j,x,y:longint;
  s:ansistring;
begin
  readln(n,k,m);readln(s);
  for i:=0 to k-1 do
    for j:=1 to n do begin
      if s[j]='0' then x:=0 else x:=1;
      if j mod k=i then a[i,j]:=a[i,j-1]+x else a[i,j]:=a[i,j-1]+(1-x);
    end;
  for i:=1 to m do begin
    readln(x,y);
    writeln((y-x+1)-(a[y mod k,y]-a[y mod k,x-1]));
  end;
end.