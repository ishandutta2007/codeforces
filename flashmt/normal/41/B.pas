uses math;
var n,b,i,x,y,re:longint;

begin
     read(n,b,x);
     re:=b;
     for i:=1 to n-1 do
     begin
          read(y);
          re:=max(re,b+(b div x)*(y-x));
          x:=min(x,y);
     end;
     writeln(re);
end.