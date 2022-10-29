var x, y: string;
    i: longint;

begin
    readln(x);
    readln(y);
    for i := 1 to length(x) do
        if x[i] < y[i] then begin
            write(-1);
            exit;
        end;
    write(y);
end.