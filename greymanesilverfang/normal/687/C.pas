var n, m, ans_cnt: longint;
    a, ans: array[1..500] of longint;
    chk: array[0..500, 0..500] of boolean;

procedure input;
var i: longint;
begin
    readln(n, m);
    for i := 1 to n do
        read(a[i]);
end;

procedure run;
var i, j, k: longint;
begin
    fillchar(chk, sizeof(chk), 0);
    chk[0, 0] := true;
    for i := 1 to n do
        for j := 500 downto 0 do
            for k := 500 downto 0 do
                if chk[j, k] then
                    if j + a[i] <= 500 then begin
                        chk[j + a[i], k] := true;
                        chk[j + a[i], k + a[i]] := true;
                    end;
    ans_cnt := 0;
    for i := 0 to 500 do
        if chk[m,i] then begin
            inc(ans_cnt);
            ans[ans_cnt] := i;
        end;
end;

procedure output;
var i: longint;
begin
    writeln(ans_cnt);
    for i := 1 to ans_cnt do
        write(ans[i], ' ');
end;

begin
    input;
    run;
    output;
end.