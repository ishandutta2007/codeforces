uses math;
var x,y,xx,yy,a,aa,e:array[1..4] of longint;
    i:longint;
    re:boolean;

function eq(m,n,z:longint):boolean;
begin
     if z=0 then eq:=(x[m]=x[n]) and (y[m]=y[n]);
     if z=1 then eq:=(x[m]=xx[n]) and (y[m]=yy[n]);
     if z=2 then eq:=(xx[m]=x[n]) and (yy[m]=y[n]);
     if z=3 then eq:=(xx[m]=xx[n]) and (yy[m]=yy[n]);
end;

procedure swap(m:longint);
var t:longint;
begin
     t:=x[m]; x[m]:=xx[m]; xx[m]:=t;
     t:=y[m]; y[m]:=yy[m]; yy[m]:=t;
end;

procedure work;
var i:Longint;
begin
     for i:=1 to 3 do
         if (xx[e[i]]<>x[e[i+1]]) or (yy[e[i]]<>y[e[i+1]]) then exit;
     if (xx[e[4]]<>x[e[1]]) or (yy[e[4]]<>y[e[1]]) then exit;
     re:=true;
end;

procedure att(z:longint);
begin
     if z>4 then
     begin
          work;
          exit;
     end;
     att(z+1);
     swap(e[z]);
     att(z+1);
     swap(e[z]);
end;

procedure check(m,n,p,q:longint);
begin
     if (a[m]=a[p]) or (aa[m]<>aa[p]) then exit;
     if (a[n]=a[q]) or (aa[n]<>aa[q]) then exit;
     if aa[m]=aa[n] then exit;
     e[1]:=m; e[2]:=n; e[3]:=p; e[4]:=q;
     att(1);
end;

begin
     for i:=1 to 4 do
     begin
          read(x[i],y[i],xx[i],yy[i]);
          if (x[i]=xx[i]) xor (y[i]=yy[i]) then
          begin
               if x[i]=xx[i] then a[i]:=x[i]
               else
               begin
                    aa[i]:=1; a[i]:=y[i];
               end;
          end
          else
          begin
               writeln('NO'); halt;
          end;
     end;
     check(1,2,3,4);
     check(1,3,2,4);
     check(1,2,4,3);
     if re then writeln('YES')
     else writeln('NO');
end.