uses math;
var n,i,x,re:longint;
    a:array[0..2] of longint;

begin
     read(n);
     fillchar(a,sizeof(a),0);
     for i:=1 to n do
     begin
          read(x);
          inc(a[x mod 3]);
     end;
     writeln(a[0] div 2+min(a[1],a[2]));
end.