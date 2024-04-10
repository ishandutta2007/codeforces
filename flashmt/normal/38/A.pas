var n,a,b,i,re:longint;
    d:array[1..200] of longint;

begin
     read(n);
     for i:=1 to n-1 do read(d[i]);
     read(a,b);
     re:=0;
     for i:=a to b-1 do re:=re+d[i];
     writeln(re);
end.