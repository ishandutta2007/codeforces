var m,n,i,j:longint;

begin
     read(m,n);
     if n*m=2 then
     begin
          writeln(0);
          writeln('1 1');
          writeln(m,' ',n);
          writeln('1 1');
          exit;
     end;
     if not odd(m) and (n>1) then
     begin
          writeln(0);
          for i:=1 to n do writeln(1,' ',i);
          for i:=2 to m do writeln(i,' ',n);
          for i:=n-1 downto 1 do writeln(m,' ',i);
          for i:=m-1 downto 2 do
              if odd(i) then
                 for j:=1 to n-1 do writeln(i,' ',j)
              else
                 for j:=n-1 downto 1 do writeln(i,' ',j);
          writeln(1,' ',1);
          exit;
     end;
     if not odd(n) and (m>1) then
     begin
          writeln(0);
          for i:=1 to m do writeln(i,' ',1);
          for i:=2 to n do writeln(m,' ',i);
          for i:=m-1 downto 1 do writeln(i,' ',n);
          for j:=n-1 downto 2 do
              if odd(j) then
                 for i:=1 to m-1 do writeln(i,' ',j)
              else
                for i:=m-1 downto 1 do writeln(i,' ',j);
          writeln(1,' ',1);
          exit;
     end;
     writeln(1);
     writeln(m,' ',n,' ',1,' ',1);
     for i:=1 to m do
         if odd(i) then
            for j:=1 to n do writeln(i,' ',j)
         else
            for j:=n downto 1 do writeln(i,' ',j);
     writeln(1,' ',1);
end.