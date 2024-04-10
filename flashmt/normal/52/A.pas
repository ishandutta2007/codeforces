uses math;
var a:array[1..3] of longint;
    n,i,x:longint;

begin
     read(n);
     a[1]:=0; a[2]:=0; a[3]:=0;
     for i:=1 to n do
     begin
          read(x);
          a[x]:=a[x]+1;
     end;
     x:=max(a[1],max(a[2],a[3]));
     writeln(n-x);
end.