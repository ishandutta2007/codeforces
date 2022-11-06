var
  a:array[0..5000,0..5000]of int64;
  b,c,d:array[0..5000]of int64;
  n,m,k,x,l,r:int64;
  i,j:longint;
begin
  readln(n,m,k);
  for i:=1 to n do begin
    read(x);b[i]:=b[i-1]+x;
  end;
  for i:=1 to k do begin
    l:=0;r:=0;c[0]:=0;d[0]:=0;
    for j:=1 to n do begin
      a[i,j]:=a[i,j-1];
      while d[l]<j-m do inc(l);
      if c[l]+b[j]>a[i,j] then
        a[i,j]:=c[l]+b[j];
      x:=a[i-1,j]-b[j];
      while (l<=r)and(x>c[r]) do dec(r);
      inc(r);c[r]:=x;d[r]:=j;
    end;
  end;
  writeln(a[k,n]);
end.