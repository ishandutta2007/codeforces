var n,x,y,d,i,x0,y0:longint;
    f:array[-888..888,-888..888] of byte;
    a,b:array[1..20] of longint;

function ok(x,y:longint):boolean;
begin
     ok:=sqr(x)+sqr(y)<=d*d;
end;

function calc(x,y:longint):byte;
var i:longint;
begin
     if f[x,y]>0 then
     begin
          calc:=f[x,y]; exit;
     end;
     calc:=1; f[x,y]:=1;
     for i:=1 to n do
         if ok(x+a[i],y+b[i]) and (calc(x+a[i],y+b[i])=2) then exit;
     calc:=2; f[x,y]:=2;
end;

begin
     read(x,y,n,d);  x0:=x; y0:=y;
     for i:=1 to n do read(a[i],b[i]);
     if calc(x,y)=1 then writeln('Anton')
     else writeln('Dasha');
end.