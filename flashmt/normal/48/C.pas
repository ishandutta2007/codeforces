const ep=0.00001;
var n,i,u,v:longint;
    a:array[0..1111] of longint;
    kt:boolean;
    l,r,m,low,high:real;

function ok(x:real):longint;
var i,y:longint; xx:real;
begin
     ok:=0; xx:=x;
     for i:=1 to n do
     begin
          y:=trunc(x/10)+a[i-1];
          if y>a[i] then
          begin
               ok:=1; exit;
          end;
          if y<a[i] then
          begin
               ok:=-1; exit;
          end;
          x:=x-(y-a[i-1])*10+xx;
     end;
end;

function go(x:real):longint;
var i:longint; xx:real;
begin
     xx:=x;
     for i:=1 to n do x:=x-(a[i]-a[i-1])*10+xx;
     go:=trunc(x/10)+a[n];
end;

begin
     read(n);
     a[0]:=0;
     for i:=1 to n do read(a[i]);
     kt:=false;
     l:=10.0; r:=100000000.0;
     while r-l>ep do
     begin
          m:=(l+r)/2;
          u:=ok(m);
          if u>=0 then
          begin
               r:=m;
               if u=0 then low:=m;
          end
          else l:=m;
     end;
     l:=10.0; r:=100000000.0;
     while r-l>ep do
     begin
          m:=(l+r)/2;
          u:=ok(m);
          if u<=0 then
          begin
               l:=m;
               if u=0 then high:=m;
          end
          else r:=m;
     end;
     u:=go(low);
     v:=go(high);
     if u=v then kt:=true;
     if not kt then writeln('not unique')
     else
     begin
          writeln('unique');
          writeln(u);
     end;
end.