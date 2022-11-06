var
  a:array[1..100000]of longint;
  n,w,i:longint;
  l,r,mid,ans:int64;
begin
  readln(n,w);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do begin
    l:=1;r:=i;mid:=(l+r) shr 1;
    while l<r do begin
      if a[i]-a[mid]>w then l:=mid+1 else r:=mid;
      mid:=(l+r) shr 1;
    end;
    inc(ans,(i-mid)*(i-mid-1));
    l:=i;r:=n;mid:=(l+r) shr 1;
    while l<r do begin
      if a[mid]-a[i]<=w then l:=mid else r:=mid-1;
      mid:=(l+r+1) shr 1;
    end;
    inc(ans,(mid-i)*(mid-i-1));
  end;
  writeln(ans div 4);
end.