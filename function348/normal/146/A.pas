var
        n,i,sum:longint;
        ch:char;
        flag:boolean;
begin
        readln(n);
        flag:=true;
        for i:=1 to n do
        begin
                read(ch);
                if (ch='4')or(ch='7') then
                if i<=n div 2 then sum:=sum+ord(ch)-48
                              else sum:=sum-ord(ch)+48
                else begin flag:=false;break;end;
        end;
        if sum<>0 then flag:=false;
        if flag then writeln('YES')
                else writeln('NO');
end.