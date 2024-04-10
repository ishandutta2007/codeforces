uses math;
var a,b,aa,bb,mx,c,re,x,y,t,base:longint;

begin
     read(a,b);
     re:=0; mx:=0;
     aa:=a; bb:=b;
     while a>0 do
     begin
          mx:=max(mx,a mod 10);
          a:=a div 10;
     end;
     while b>0 do
     begin
          mx:=max(mx,b mod 10);
          b:=b div 10;
     end;
     a:=aa; b:=bb;
     for base:=mx+1 to 16 do
     begin
          x:=0; y:=0; t:=1;
          aa:=a; bb:=b;
          while aa>0 do
          begin
               x:=x+(aa mod 10)*t;
               aa:=aa div 10;
               t:=t*base;
          end;
          t:=1;
          while bb>0 do
          begin
               y:=y+(bb mod 10)*t;
               bb:=bb div 10;
               t:=t*base;
          end;
          x:=x+y;
          t:=0;
          while x>0 do
          begin
               inc(t);
               x:=x div base;
          end;
          if t>re then re:=t;
     end;
     writeln(re);
end.