var
  p:array[1..6]of longint;
  n,i,j,x,y,p1,p2,w1,w2,c1,c2:longint;
begin
  readln(n);readln(p1);
  for i:=1 to n do begin
    readln(x,y);
    fillchar(p,sizeof(p),0);
    if x+y=7 then begin
      writeln('NO');exit;
    end;
    p[x]:=1;p[y]:=1;
    p[7-x]:=1;p[7-y]:=1;
    for j:=1 to 6 do
      if p[j]=0 then
        if w1=0 then w1:=j else w2:=j;
    if (p2=0)or(p[p2]=1) then p2:=0;
    if (p1=0)or(p[p1]=1) then p1:=p2;
    if p1=0 then begin
      writeln('NO');exit;
    end;
    if (w1<>7-p1)or(w1<>7-p2)and(i>1) then c1:=w1;
    if (w2<>7-p1)or(w2<>7-p2)and(i>1) then
      if c1=0 then c1:=w2 else c2:=w2;
    p1:=c1;p2:=c2;
    if p1=0 then begin
      writeln('NO');exit;
    end;
  end;
  writeln('YES');
end.