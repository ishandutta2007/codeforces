var n,i,j,re:longint;
begin
     read(n);
     writeln(sqr(n div 2)+ord(odd(n))*(n div 2));
     for i:=1 to n div 2 do
      for j:=n div 2+1 to n do
        writeln(i,' ',j);
end.