var
  a,b:array[1..200000,1..40]of longint;
  w:array[1..200000]of longint;
  sm,pr,p,d:array[1..3000000]of int64;
  n,q,xe,al,i,j,k,x,l,r,mid:longint;
  ans:int64;
function gcd(x,y:longint):longint;
begin
  if y=0 then exit(x) else exit(gcd(y,x mod y));
end;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;x:=sm[(l+r) shr 1];
  repeat
    while sm[i]<x do inc(i);
    while x<sm[j] do dec(j);
    if i<=j then begin
      y:=sm[i];sm[i]:=sm[j];sm[j]:=y;
      y:=pr[i];pr[i]:=pr[j];pr[j]:=y;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  for i:=1 to n do read(w[i]);
  for i:=n downto 1 do begin
    a[i,1]:=w[i];b[i,1]:=1;j:=1;k:=1;
    while a[i+1,k]<>0 do begin
      if gcd(a[i+1,k],w[i])<>a[i,j] then begin
        inc(j);a[i,j]:=gcd(a[i+1,k],w[i]);
      end;
      inc(b[i,j],b[i+1,k]);inc(k);
    end;
  end;
  for i:=n downto 1 do begin
    j:=1;
    while a[i,j]<>0 do begin
      inc(xe);sm[xe]:=a[i,j];
      pr[xe]:=b[i,j];inc(j);
    end;
  end;
  sort(1,xe);al:=1;p[1]:=sm[1];d[1]:=pr[i];
  for i:=2 to xe do begin
    if sm[i]<>sm[i-1] then begin
      inc(al);p[al]:=sm[i];
    end;
    inc(d[al],pr[i]);
  end;
  readln(q);
  for i:=1 to q do begin
    readln(x);l:=1;r:=al;
    mid:=(l+r) shr 1;ans:=0;
    while l<=r do begin
      if p[mid]=x then begin
        ans:=d[mid];break;
      end;
      if p[mid]>x then r:=mid-1 else l:=mid+1;
      mid:=(l+r) shr 1;
    end;
    writeln(ans);
  end;
end.