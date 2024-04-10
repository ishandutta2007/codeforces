var n,i,t: longint;
    x: longint = 0;
    dir: string;
begin
    read(n);
    for i:=1 to n do
    begin
        read(t); readln(dir);
        if dir=' North'
           then dec(x,t)
        else if dir=' South'
             then inc(x,t)
        else if (x=0)or(x=20000)
             then begin
                 write('NO');
                 exit;
             end;
        if (x<0)or(x>20000) then
        begin
            write('NO');
            exit;
        end;
    end;
    if x=0 then write('YES') else write('NO');
end.