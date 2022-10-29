var s: string;
    cnt, i: longint;
    chk: boolean;

begin
    read(s);
    cnt := 0;
    chk := false;
    for i := 1 to length(s) - 1 do begin
        if (s[i] = 'V') and (s[i+1] = 'K') then
            inc(cnt)
        else if not ((s[i] = 'K') and (s[i+1] = 'V')) and not ((i > 1) and (s[i-1] = 'V') and (s[i] = 'K')) and not ((i+1 < length(s)) and (s[i+1] = 'V') and (s[i+2] = 'K')) then
            chk := true;
    end;
    write(cnt + ord(chk));
end.