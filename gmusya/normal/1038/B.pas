var n,s,s1,s2,i: longint;
begin
readln (n);
if (n mod 2)=0 then s:=(n+1)*(n div 2)
else s:=n*((n-1) div 2)+n;
if n<3 then writeln ('No');
if n=3 then 
    begin
    writeln ('Yes');
    writeln ('1 2');
    writeln ('2 1 3');
    end;
if n>3 then
    begin
    s1:=n;
    s2:=s-n;
    writeln ('Yes');
    write (n-1, ' '); for i:=1 to n-1 do write (i, ' ');
    writeln;
    writeln (1, ' ', n);
    end;
end.