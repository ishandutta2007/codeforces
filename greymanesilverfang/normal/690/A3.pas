var T, N, R, a, b, x: longint;
begin
read(T);
for a := 1 to T do
    begin
    read(N, R);
    for b := 1 to N-1 do
        begin
        read(x);
        R := R+x;
        end;
    writeln(N-(R mod N));
    end;
end.