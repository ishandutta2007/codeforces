function rank(a: int64): byte;
    var 
    x, i: byte;
    y: int64;
    begin
    if a < 16777216 then rank := 0 else
        begin
        x := 1;
        y := 1;
        for i := 1 to 25 do y := y*2;
        while y <= a do
            begin
            x := x + 1;
            y := 2*y;
            end;
        rank := x;
        end;
    end;
function locate(a, rank_a: int64; var b: array of int64): longint;
    var 
    i: integer;
    begin
    if rank_a = 0 then locate := -a else
        begin
        i := 0;
        while (b[36*i + rank_a] > 0) and (b[36*i + rank_a] <> a) do i := i + 1;
        if b[36*i + rank_a] = 0 then b[36*i + rank_a] := a;
        locate := 36*i + rank_a;
        end;
    end;
var
b, rank_v, rank_u: byte;
q, a: integer;
location: longint;
v, u, w, pay: int64;
utility: array[1..72000] of int64;
fee: array[-16777215..72000] of int64;
begin
read(q);
for a := 1 to q do
    begin
    read(b);
    if b = 1 then
        begin
        read(v, u, w);
        rank_v := rank(v);
        rank_u := rank(u);
        while v <> u do
            begin
            if v > u then
                begin
                location := locate(v, rank_v, utility);
                fee[location] := fee[location] + w;
                v := v div 2;
                if rank_v > 0 then rank_v := rank_v - 1;
                end
            else
                begin
                location := locate(u, rank_u, utility);
                fee[location] := fee[location] + w;
                u := u div 2;
                if rank_u > 0 then rank_u := rank_u - 1;
                end;
            end;
        end
    else
        begin
        pay := 0;
        read(v, u);
        rank_v := rank(v);
        rank_u := rank(u);
        while v <> u do
            begin
            if v > u then
                begin
                location := locate(v, rank_v, utility);
                pay := pay + fee[location];
                v := v div 2;
                if rank_v > 0 then rank_v := rank_v - 1;
                end
            else
                begin
                location := locate(u, rank_u, utility);
                pay := pay + fee[location];
                u := u div 2;
                if rank_u > 0 then rank_u := rank_u - 1;
                end;
            end;
        writeln(pay);
        end;
    end;
end.