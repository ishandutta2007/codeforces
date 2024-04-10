uses math;
var n,i,c,d: longint;
    low1: longint=high(longint);
    high2: longint=low(longint);
    x: longint=0;
    chk: boolean=false;
begin
    readln(n);
    for i:=1 to n do
    begin
        read(c,d);
        if d=1 then low1 := min(x,low1)
        else begin
            high2 := max(x,high2);
            chk := true;
        end;
        inc(x,c);
        if high2>=low1 then
        begin
            write('Impossible');
            exit;
        end;
    end;
    if chk then write(1899-high2+x) else write('Infinity');
    readln;
end.