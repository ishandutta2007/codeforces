program qwe;

uses Math;

const maxN = 222222;

var
    s: string;
    a: array[1..maxN] of integer;
    i, n, k, l, r, m: integer;
    lst, count: integer;
    ok: boolean;

begin
    readln(n, k);
    readln(s);
    
    l := 1;
    r := n;
    
    ok := true;
    for i := 1 to n do
    begin
        if s[i] = '1' then ok := false;
    end;
    if k < n then ok := false;
    
    if ok = true then
    begin
        writeln(0);
        halt(0);
    end;
    
    while r - l > 1 do
    begin
        m := (l + r) div 2;
        lst := 0;
        for i := 1 to m do
        begin
            if s[i] = '0' then lst := i;
        end;
        for i := 1 to n do
        begin
            if (i + m <= n) and (s[i + m] = '0') then lst := i + m;
            a[i] := lst;
        end;
        
        count := 0;
        i := 1;
        while i < n do
        begin
            if (a[i] = i) then
            begin
                i := n;
                count := 1000000;
            end;
            i := a[i];
            count := count + 1;
        end;
        if count + 1 > k then
            l := m
        else
            r := m;
    end;
    writeln(l);
end.