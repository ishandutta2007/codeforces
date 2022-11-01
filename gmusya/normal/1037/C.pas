var n,i,k: longint;
    s1,s2:string;
begin
readln (n);
readln (s1);
readln (s2);
i:=1;
while (i<=n) do
    begin 
    if (i=n) and (s1[i]<>s2[i]) then k:=k+1 else
    if (i<n) and (s1[i]<>s2[i]) then
        begin
        if (s1[i+1]<>s1[i]) and (s1[i+1]<>s2[i+1]) then
            begin
            i:=i+1;
            k:=k+1;
            end else
        k:=k+1;
        end;
    i:=i+1;
    end;
writeln (k);
end.