const fi='';
      g=9.8;
var n,v,m,i,cur:longint;
    a,rx,ry:array[1..10010] of real;
    p:array[1..10010] of longint;
    b,c:Array[1..100010] of real;
    x,y:real;

procedure sort(l,r:Longint);
var i,j:longint; x,y:real;
begin
     i:=l; j:=r; x:=b[(i+j) shr 1];
     repeat
           while b[i]<x do i:=i+1;
           while b[j]>x do j:=j-1;
           if i<=j then
           begin
                y:=b[i]; b[i]:=b[j]; b[j]:=y;
                y:=c[i]; c[i]:=c[j]; c[j]:=y;
                i:=i+1; j:=j-1;
           end;
     until i>j;
     if i<r then sort(i,r);
     if l<j then sort(l,j);
end;

procedure sortt(l,r:longint);
var i,j,t:longint; x,y:real;
begin
     i:=l; j:=r; x:=a[(i+j) shr 1];
     repeat
           while a[i]<x do i:=i+1;
           while a[j]>x do j:=j-1;
           if i<=j then
           begin
                y:=a[i]; a[i]:=a[j]; a[j]:=y;
                t:=p[i]; p[i]:=p[j]; p[j]:=t;
                i:=i+1; j:=j-1;
           end;
     until i>j;
     if i<r then sortt(i,r);
     if l<j then sortt(l,j);
end;

function check(a,b,c:real;var x,y:real):boolean;
var t:real;
begin
     check:=true;
     t:=b/(v*cos(a));
     y:=t*v*sin(a)-g*t*t/2;
     if y>c then exit;
     check:=false;
     if y>=0 then
     begin
          x:=b; exit;
     end;
     y:=0;
     t:=sin(a)*v*2/g;
     x:=t*cos(a)*v;
end;

begin
     assign(input,fi); reset(input);
     read(n,v);
     for i:=1 to n do
     begin
          read(a[i]);
          p[i]:=i;
     end;
     read(m);
     for i:=1 to m do read(b[i],c[i]);
     sort(1,m);
     sortt(1,n);
     inc(m);
     b[m]:=10000000; c[m]:=10000000;
     cur:=1;
     for i:=1 to n do
     begin
          while check(a[i],b[cur],c[cur],x,y) do cur:=cur+1;
          rx[p[i]]:=x; ry[p[i]]:=y;
     end;
     for i:=1 to n do writeln(rx[i]:0:9,' ',ry[i]:0:9);
     close(input);
end.