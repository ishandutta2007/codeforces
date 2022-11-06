const mx:int64=1000000007;
var
  a:array[0..200000]of int64;
  b:array[0..1000]of int64;
  p,n,m,i,j,ans:longint;
begin
  readln(n,m);a[0]:=1;
  for i:=1 to 1000 do begin
    b[i]:=b[i-1]+i;
    if b[i]>n+m then begin
      p:=i-1;break;
    end;
  end;
  for i:=1 to p do
    for j:=n downto 0 do begin
      if (b[i]-j-i<=m)and(j+i<=n) then begin
        inc(a[j+i],a[j]);
        if a[j+i]>=mx then dec(a[j+i],mx);
      end;
      if b[i]-j>m then a[j]:=0;
    end;
  for j:=0 to n do begin
    inc(ans,a[j]);
    if ans>mx then dec(ans,mx);
  end;
  writeln(ans);
end.