const r='aeiouyAEIOUY';
var s:ansistring; i:longint;
begin
     readln(s);
     for i:=length(s) downto 1 do
         if ((s[i]>='a') and (s[i]<='z')) or ((s[i]>='A') and (s[i]<='Z')) then break;
     if pos(s[i],r)>0 then writeln('YES')
     else writeln('NO');
end.