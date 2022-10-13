uses math;
var n,i,j,z:longint;
    oo,t:int64;
    x,c:array[1..3000] of longint;
    f:array[0..1,0..3000] of int64;

procedure sort(l,r:longint);
var i,j,t,y:longint;
begin
     i:=l; j:=r; y:=x[(i+j) shr 1];
     repeat
           while x[i]>y do i:=i+1;
           while x[j]<y do j:=j-1;
           if i<=j then
           begin
                t:=x[i]; x[i]:=x[j]; x[j]:=t;
                t:=c[i]; c[i]:=c[j]; c[j]:=t;
                i:=i+1; j:=j-1;
           end;
     until i>j;
     if i<r then sort(i,r);
     if l<j then sort(l,j);
end;

begin
     read(n);
     for i:=1 to n do read(x[i],c[i]);
     sort(1,n);
     fillchar(f,sizeof(f),0);
     f[1,0]:=c[1];
     z:=1;
     oo:=1000000000; oo:=oo*oo;
     for i:=2 to n do
     begin
          z:=i and 1;
          f[z,0]:=oo;
          for j:=0 to i-1 do
          begin
               t:=int64(j)*(x[i-1]-x[i]);
               f[z,0]:=min(f[z,0],f[1-z,j]+t+c[i]);
               f[z,j+1]:=f[1-z,j]+t;
          end;
     end;
     writeln(f[z,0]);
end.