var j,n,i,re:longint;
    kt:boolean;
    a:array[1..100] of string;

begin
     re:=0;
     readln(n);
     for i:=1 to n do
     begin
          readln(a[i]);
          kt:=true;
          for j:=i-1 downto 1 do
           if a[j]=a[i] then kt:=false;
          if kt then inc(re);
     end;
     writeln(re);
end.