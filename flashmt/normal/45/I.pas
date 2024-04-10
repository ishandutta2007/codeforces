var n,i,j,t,x,y:longint;
    a,b:array[1..100] of longint;
    zr:boolean;

begin
     read(n);
     x:=0; y:=0;
     zr:=false;
     for i:=1 to n do
     begin
          read(t);
          if t=0 then
          begin
               zr:=true; continue;
          end;
          if t>0 then
          begin
               inc(x); a[x]:=t;
          end
          else
          begin
               inc(y); b[y]:=t;
          end;
     end;
     for i:=1 to y-1 do
      for j:=i+1 to y do
       if b[i]>b[j] then
       begin
            t:=b[i]; b[i]:=b[j]; b[j]:=t;
       end;
     for i:=1 to x do write(a[i],' ');
     if y>1 then for i:=1 to y shr 1 shl 1 do write(b[i],' ')
     else
     begin
          if (x=0) and not zr then write(b[1],' ')
          else
          begin
               if x=0 then write(0,' ');
          end;
     end;
end.