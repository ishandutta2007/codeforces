var n, m, cnt, ans_cnt, max: longint;
    a, ans: array[0..15] of string;
    b, c: array[1..120] of string;
    hate: array[0..15, 0..15] of boolean;

procedure input;
var i, j: longint;
    S: string;
begin
    readln(n, m);
    for i := 0 to n - 1 do
        readln(a[i]);
    for i := 1 to m do begin
        readln(S);
        for j := 1 to length(S) do
            if S[j] = ' ' then
                break;
        b[i] := copy(S, 1, j - 1);
        c[i] := copy(S, j + 1, length(S) - j);
    end;
end;

procedure run;
var i, j, k: longint;
    tmp: string;
    function chk: boolean;
    var j, k, l: longint;
    begin
        for j := 0 to n - 1 do
            for k := 0 to n - 1 do
                if odd(i shr j) and odd(i shr k) and hate[j, k] then
                    exit(false);
        k := 0;
        l := 0;
        for j := 0 to n - 1 do begin
            if odd(i shr j) then
                inc(k);
            if odd(max shr j) then
                inc(l);
        end;
        exit(k > l);
    end;
begin
    for i := 0 to n - 1 do
        for j := i + 1 to n - 1 do
            if a[i] > a[j] then begin
                tmp := a[i];
                a[i] := a[j];
                a[j] := tmp;
            end;
    fillchar(hate, sizeof(hate), 0);
    for i := 1 to m do
        for j := 0 to n - 1 do
            for k := 0 to n - 1 do
                if (b[i] = a[j]) and (c[i] = a[k]) then
                    hate[j, k] := true;
    cnt := 1 shl n - 1;
    max := 0;
    for i := 0 to cnt do
        if chk then
            max := i;
    ans_cnt := 0;
    for i := 0 to n - 1 do
        if odd(max shr i) then begin
            inc(ans_cnt);
            ans[ans_cnt] := a[i];
        end;
end;

procedure output;
var i: longint;
begin
    writeln(ans_cnt);
    for i := 1 to ans_cnt do
        writeln(ans[i]);
end;

begin
    input;
    run;
    output;
end.