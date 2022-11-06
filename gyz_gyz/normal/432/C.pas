var
  a,b,ht:array[1..200000]of longint;
  w1,w2:array[1..500000]of longint;
  n,i,j,ans,x,tp:longint;
procedure swap(x,y:longint);
begin
  inc(ans);w1[ans]:=x;w2[ans]:=y;
  b[a[x]]:=y;b[a[y]]:=x;
  tp:=a[x];a[x]:=a[y];a[y]:=tp;
end;
procedure cg(x:longint);
var i:longint;
begin
  i:=b[x];
  while i<>x do begin
    swap(x+ht[i-x+1],i);
    i:=x+ht[i-x+1];
  end;
end;
begin
  readln(n);x:=1;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do b[a[i]]:=i;
  for i:=2 to n do begin
    tp:=0;
    for j:=2 to trunc(sqrt(i)) do
      if i mod j=0 then begin
        tp:=1;break;
      end;
    if tp=0 then x:=i;
    ht[i]:=i-x;
  end;
  for i:=1 to n do cg(i);
  writeln(ans);
  for i:=1 to ans do
    writeln(w1[i],' ',w2[i]);
end.