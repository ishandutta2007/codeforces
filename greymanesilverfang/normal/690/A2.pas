var N, p: longint;
begin
read(N);
if (N mod 2) = 1 then writeln(N div 2) else
    begin
    p := 2;
    while N >= 2*p do p := 2*p;
    writeln((N - p) div 2);
    end;
end.