var m,n,x,r,rr:longint;

function calc(m,n,x:longint):longint;
var re,a,b,c,u,v:longint;
begin
     a:=x; b:=m-x+1; c:=n-x+1;
     u:=b-a+1; v:=c-a+1;
     if (u<0) or (v<0) then calc:=0
     else calc:=(u*v+1) shr 1;
end;

begin
     read(m,n,x);
     r:=calc(m,n,x);
     rr:=calc(m,n,x+1);
     writeln(r-rr);
end.