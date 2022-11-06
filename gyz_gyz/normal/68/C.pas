var
  l,h,a:array[1..6,1..6]of longint;
  sl:array[1..6]of longint;
  n,i,x1,x2,x3,x4,x5,tp,an1,an2:longint;
procedure f(x,y,pa,sa:longint);
var i,j:longint;
begin
  if y>=n then begin
    inc(x);y:=x+1;
    if (x>2)and((sl[x-1]<l[x-1,n])or(sl[x-1]>h[x-1,n])) then exit;
  end;
  if y>=n then begin
    if (sl[x]<l[x,n])or(sl[x]>h[x,n]) then exit;
    for i:=2 to n-1 do
      if sl[i]>0 then inc(pa,sl[i]*sl[i]+a[i,n]);
    if l[1,n]>0 then begin
      inc(pa,l[1,n]*l[1,n]+a[1,n]);inc(sa,l[1,n]);
    end;
    if (sa<an1)or(sa=an1)and(pa>an2) then begin
      an1:=sa;an2:=pa;
    end;
    exit;
  end;
  for i:=l[x,y] to h[x,y] do begin
    dec(sl[x],i);inc(sl[y],i);
    if i>0 then inc(pa,i*i+a[x,y]);
    if x=1 then inc(sa,i);
    f(x,y+1,pa,sa);
    if x=1 then dec(sa,i);
    if i>0 then dec(pa,i*i+a[x,y]);
    inc(sl[x],i);dec(sl[y],i);
  end;
end;
begin
  readln(n);an1:=100;an2:=-1;
  for i:=1 to n*(n-1) div 2 do begin
    readln(x1,x2,x3,x4,x5);
    l[x1,x2]:=x3;h[x1,x2]:=x4;a[x1,x2]:=x5;
    l[x2,x1]:=x3;h[x2,x1]:=x4;a[x2,x1]:=x5;
  end;
  f(1,2,0,0);
  if an2=-1 then writeln('-1 -1')
  else writeln(an1,' ',an2);
end.