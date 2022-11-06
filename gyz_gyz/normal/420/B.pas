var
  a,b,w,ww,q,wr:array[1..100000]of longint;
  n,m,i,p,x,ans:longint;
  c:char;
begin
  readln(n,m);
  for i:=1 to m do begin
    readln(c,a[i]);
    if c='+' then b[i]:=1 else b[i]:=-1;
  end;
  for i:=1 to m do begin
    if w[a[i]]=0 then begin
      if b[i]=-1 then begin
        w[a[i]]:=1;inc(p);
      end else w[a[i]]:=-1;
    end;
  end;
  for i:=m downto 1 do
    if ww[a[i]]=0 then
      if b[i]=-1 then ww[a[i]]:=1
      else ww[a[i]]:=-1;
  for i:=1 to n do
    if w[i]=-1 then w[i]:=0;
  if p>0 then x:=1 else x:=0;
  for i:=1 to m do begin
    if b[i]=-1 then begin
      w[a[i]]:=x;dec(p);
      if p>0 then q[a[i]]:=1;
    end;
    if b[i]=1 then begin
      if w[a[i]]<x then q[a[i]]:=1;
      inc(p);
      if p=1 then inc(x);
    end;
  end;
  for i:=1 to n do
    if (ww[i]=1)and(w[i]<x) then q[i]:=1;
  for i:=1 to n do
    if q[i]=0 then inc(ans);
  writeln(ans);x:=0;
  for i:=1 to n do
    if q[i]=0 then begin
      inc(x);wr[x]:=i;
    end;
  for i:=1 to x-1 do write(wr[i],' ');
  if x>0 then writeln(wr[x]);
end.