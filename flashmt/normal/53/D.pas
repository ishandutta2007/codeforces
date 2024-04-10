var n,i,j,re,t:longint;
    a,b:array[1..333] of longint;
    r:array[1..1111111] of longint;

begin
     read(n);
     for i:=1 to n do read(a[i]);
     for i:=1 to n do read(b[i]);
     for i:=1 to n do
     begin
          for j:=i to n do
              if b[j]=a[i] then break;
          while j>i do
          begin
               re:=re+1;
               r[re]:=j-1;
               t:=b[j]; b[j]:=b[j-1]; b[j-1]:=t;
               j:=j-1;
          end;
     end;
     writeln(re);
     for i:=1 to re do writeln(r[i],' ',r[i]+1);
end.