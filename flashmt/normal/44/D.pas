uses math;
var n,i,j:longint;
    x,y,z:array[1..5005] of longint;
    f:array[1..5005] of real;
    re,c,cc,ccc:real;

function d(x,y,z,xx,yy,zz:longint):real;
begin
     d:=sqrt(sqr(x-xx)+sqr(y-yy)+sqr(z-zz));
end;

begin
     read(n);
     for i:=1 to n do read(x[i],y[i],z[i]);
     for i:=2 to n do f[i]:=d(x[1],y[1],z[1],x[i],y[i],z[i]);
     re:=1000000000;
     for i:=2 to n do
      for j:=i+1 to n do
      begin
           c:=d(x[i],y[i],z[i],x[j],y[j],z[j]);
           if f[i]>=f[j] then cc:=f[i] else cc:=f[j];
           ccc:=f[i]+f[j]-cc;
           if (cc-ccc<=c) then re:=min(re,cc+(c-cc+ccc)/2);
      end;
     writeln(re:0:9);
end.