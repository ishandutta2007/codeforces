uses math;

var n, m, tmp, ans, i, j, k: longint;
    s: array[1..50] of string;

begin
    readln(n);
    for i := 1 to n do
        readln(s[i]);
    m := length(s[1]);
    ans := high(longint);
    for i := 1 to n do begin
        tmp := 0;
        for j := 1 to n do
            if (s[i] <> s[j]) then
                for k := 0 to m do
                    if k = m then begin
                        write(-1);
                        exit;
                    end else if copy(s[j],k+1,m-k)+copy(s[j],1,k)=s[i] then begin
                        inc(tmp, k);
                        break;
                    end;
        ans := min(ans, tmp);
    end;
    write(ans);
end.