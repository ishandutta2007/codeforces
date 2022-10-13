var m,n,i,j,x,y:longint;
    a:array[1..100] of longint;

function check:boolean;
var i:longint;
begin
     for i:=1 to n do
         if a[i]<>1 then
         begin
              writeln(i,' ',a[i]);
              check:=false;
              exit;
         end;
     check:=true;
end;

begin
     read(n,m);
     fillchar(a,sizeof(a),0);
     for i:=1 to m do
     begin
          read(x,y);
          for j:=x to y do inc(a[j]);
     end;
     if check then writeln('OK');
end.