uses math;
var n,m,i,j,maxx,maxy,minx,miny:longint;
    a:array[1..100,1..100] of char;

begin
     readln(m,n);
     minx:=m; miny:=n;
     for i:=1 to m do
     begin
          for j:=1 to n do
          begin
               read(a[i,j]);
               if a[i,j]='*' then
               begin
                    maxx:=max(maxx,i);
                    minx:=min(minx,i);
                    maxy:=max(maxy,j);
                    miny:=min(miny,j);
               end;
          end;
          readln;
     end;
     for i:=minx to maxx do
     begin
          for j:=miny to maxy do write(a[i,j]);
          writeln;
     end;
end.