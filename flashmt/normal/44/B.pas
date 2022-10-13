var re,n,a,b,c,i,j,bb,cc:longint;

begin
     read(n,a,b,c);
     re:=0;
     if c<n div 2 then cc:=c else cc:=n div 2;
     for i:=0 to cc do
     begin
          if b<n-i*2 then bb:=b else bb:=n-i*2;
          for j:=0 to bb do
              if (n-i*2-j)*2<=a then re:=re+1;
     end;
     writeln(re);
end.