var x,y,re,b:longint;
    a:real;

begin
     read(x,y);
     a:=sqrt(x*x+y*y);
     b:=trunc(a);
     if a=b then writeln('black')
     else
     begin
          inc(b);
          if (x*y>0) then re:=b and 1
          else re:=1-b and 1;
          if re=1 then writeln('black')
          else writeln('white');
     end;
end.