var n,i,j:longint;
    a,b,m:real;
    x,y,xx,yy,gx,gy,l:array[1..111] of real;
    re:array[1..111] of boolean;

function ins(t,u,v:real):boolean;
begin
     ins:=(t-u)*(t-v)<=0;
end;

begin
     read(n);
     for i:=1 to n do
     begin
          read(x[i],y[i],xx[i],yy[i]);
          gx[i]:=(x[i]+xx[i])/2;
          gy[i]:=(y[i]+yy[i])/2;
          l[i]:=xx[i]-x[i];
          if l[i]<0 then l[i]:=-l[i];
          l[i]:=l[i]*l[i]*l[i];
     end;
     fillchar(re,sizeof(re),false);
     for i:=n downto 2 do
     begin
          a:=gx[i]; b:=gy[i]; j:=i-1; m:=l[i];
          while ins(a,x[j],xx[j]) and ins(b,y[j],yy[j]) do
          begin
               a:=a-(a-gx[j])*l[j]/(m+l[j]);
               b:=b-(b-gy[j])*l[j]/(m+l[j]);
               m:=m+l[j];
               dec(j);
               if j=0 then
               begin
                    re[i]:=true; break;
               end;
          end;
     end;
     for i:=2 to n+1 do
         if not re[i] then
         begin
              writeln(i-1); halt;
         end;
end.