const mx=131072;
var
  a:array[1..mx]of longint;
  n,m,x,t,p,q,r,tn,cg,i,j:longint;
procedure ins(x,y:longint);inline;
begin
  while x<=mx do begin
    inc(a[x],y);inc(x,x and (-x));
  end;
end;
function fd(x:longint):longint;inline;
var y:longint;
begin
  y:=0;
  while x>=1 do begin
    inc(y,a[x]);dec(x,x and (-x));
  end;
  exit(y);
end;
begin
  readln(n,m);r:=n;
  for i:=1 to n do ins(i,1);
  for i:=1 to m do begin
    read(t);
    if t=1 then begin
      readln(p);cg:=0;
      if x+p+p>r then begin
        cg:=1;tn:=1-tn;
      end;
      if (cg=0)and(tn=1) then p:=r-x-p;
      if (cg=1)and(tn=0) then p:=r-x-p;
      if tn=0 then begin
        for j:=x+1 to x+p do begin
          ins(x+x+p+p-j+1,fd(j)-fd(j-1));
        end;
        inc(x,p);
      end else begin
        for j:=r downto x+p+1 do begin
          ins(x+x+p+p-j+1,fd(j)-fd(j-1));
        end;
        r:=x+p;
      end;
    end else begin
      readln(p,q);
      if tn=0 then writeln(fd(x+q)-fd(x+p))
      else writeln(fd(r-p)-fd(r-q));
    end;
  end;
end.