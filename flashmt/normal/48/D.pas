var n,i,x,p:longint;
    a,d:array[1..100010] of longint;

begin
     read(n);
     p:=0;
     fillchar(d,sizeof(d),0);
     for i:=1 to n do
     begin
          read(x);
          if x>p then p:=x;
          inc(d[x]);
          a[i]:=d[x];
     end;
     for i:=1 to p-1 do
         if d[i]<d[i+1] then
         begin
              writeln(-1); exit;
         end;
     writeln(d[1]);
     for i:=1 to n do write(a[i],' ');
     writeln;
end.