uses math;
var n,i,j,a,b,re,x:longint;
    d:array[0..1000] of longint;

begin
     read(n,x);
     for i:=1 to n do
     begin
          read(a,b);
          if a>b then
          begin
               j:=a; a:=b; b:=j;
          end;
          for j:=a to b do inc(d[j]);
     end;
     re:=maxlongint;
     for i:=0 to 1000 do
         if d[i]=n then re:=min(re,abs(i-x));
     if re=maxlongint then writeln(-1)
     else writeln(re);
end.