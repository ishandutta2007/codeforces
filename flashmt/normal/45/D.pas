var n,i,j,t,min,x,y:longint;
    l,r,
    re,a:array[1..100] of longint;
    f:array[1..100] of boolean;
    e:array[1..10000001] of boolean;

begin
     read(n);
     for i:=1 to n do
     begin
          read(l[i],r[i]);
          a[i]:=r[i]-l[i];
          f[i]:=true;
     end;
     for i:=1 to n do
     begin
          min:=100000000; x:=0;
          for j:=1 to n do
           if f[j] and ((a[j]<min) or ((a[j]=min) and (l[j]<x))) then
           begin
                min:=a[j]; x:=l[j];
                y:=j;
           end;
          for j:=l[y] to r[y] do
              if not e[j] then break;
          re[y]:=j; e[j]:=true; f[y]:=false;
          for j:=1 to n do
              if f[j] and (re[y]>=l[j]) and (re[y]<=r[j]) then dec(a[j]);
     end;
     for i:=1 to n do write(re[i],' ');
     writeln;
end.