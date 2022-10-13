uses math;
var n,l,i,x,mx,re,y:longint;
    a:array[1..100] of longint;

begin
     read(n,l);
     re:=0; mx:=0;
     for i:=1 to n do
     begin
          read(a[i]);
          mx:=max(mx,a[i]);
     end;
     for x:=l to mx do
     begin
          y:=0;
          for i:=1 to n do y:=y+a[i] div x;
          re:=max(re,x*y);
     end;
     writeln(re);
end.