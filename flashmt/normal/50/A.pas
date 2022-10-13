uses math;
var m,n,re:longint;
begin
     read(m,n);
     if m mod 2=0 then re:=m div 2*n
     else
     begin
          if n mod 2=0 then re:=n div 2*m
          else re:=min(n div 2*m+m div 2,m div 2*n+n div 2);
     end;
     writeln(re);
end.