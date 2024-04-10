uses math;
var m,n,a,b,i,j,re:longint;
    f:array[0..100,0..100] of longint;

function calc(x,y,xx,yy:longint):longint;
begin
     calc:=f[xx,yy]-f[x-1,yy]-f[xx,y-1]+f[x-1,y-1];
end;

procedure check(a,b:longint);
begin
     for i:=1 to m-a+1 do
      for j:=1 to n-b+1 do
       re:=min(re,calc(i,j,i+a-1,j+b-1));
end;

begin
     read(m,n);
     fillchar(f,sizeof(f),0);
     for i:=1 to m do
      for j:=1 to n do
      begin
           read(a);
           f[i,j]:=f[i,j-1]+f[i-1,j]-f[i-1,j-1]+a;
      end;
     read(a,b);
     re:=f[m,n];
     check(a,b);
     check(b,a);
     writeln(re);
end.