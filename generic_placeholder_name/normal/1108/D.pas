var s, ans: ansistring;
        tmp: char;
        i, j, k, c: longint;
begin
readln(i);
readln(s);
s:=s+'0'; i:=1; ans:='';
while i<length(s) do
        begin
        if s[i]=s[i+1] then
                begin
                j:=i+1;
                while s[j+1]=s[j] do j:=j+1;
                if (s[i]='R') and ((s[j+1]='G') or (s[j+1]='0')) then tmp:='B'
                else if s[i]='R' then tmp:='G'
                else if (s[i]='G') and ((s[j+1]='R') or (s[j+1]='0')) then tmp:='B'
                else if s[i]='G' then tmp:='R'
                else if (s[j+1]='G') or (s[j+1]='0') then tmp:='R'
                else tmp:='G';
                for k:=i to j do
                        if (k-i) mod 2 = 1 then
                                begin
                                c:=c+1;
                                ans:=ans+tmp;
                                end
                        else ans:=ans+s[i];
                i:=j+1;
                end
        else begin
                ans:=ans+s[i]; i:=i+1;
                end;
        end;
writeln(c);
writeln(ans);
end.