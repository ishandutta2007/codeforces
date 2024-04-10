    var n,u,i,j:longint;d,ma,xx,yy,zz:double;x,y,z:array[0..200]of longint;begin read(n);for i:=1 to n do read(x[i],y[i],z[i]);d:=1;for i:=1 to 100000 do begin u:=0;
        ma:=-1;for j:=1 to n do
          if sqr(x[j]-xx)+sqr(y[j]-yy)+sqr(z[j]-zz)>ma then begin
            ma:=sqr(x[j]-xx)+sqr(y[j]-yy)+sqr(z[j]-zz);
            u:=j;
          end;
        xx:=xx+d*(x[u]-xx);
        yy:=yy+d*(y[u]-yy);
        zz:=zz+d*(z[u]-zz);
        d:=d*0.999;
      end;write(xx:0:12,' ',yy:0:12,' ',zz:0:12);end.