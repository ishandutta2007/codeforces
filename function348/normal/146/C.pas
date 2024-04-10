var
        s1,s2:ansistring;
        n,i,a,b:longint;
begin
        readln(s1);n:=length(s1);
        readln(s2);
        for i:=1 to n do
        begin
                if (s1[i]='4')and(s2[i]='7') then inc(a);
                if (s1[i]='7')and(s2[i]='4') then inc(b);
        end;
        if a>b then writeln(a)
               else writeln(b);
end.