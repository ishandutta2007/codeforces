type
    point = record
        k, l: integer;
        end;
    a2d = array of array of byte;
function checkedge(a, b: point; pa: a2d; ars: integer): boolean;
    var
        x, y, z, m, n, data: integer;
        cdata: boolean;
    begin
    x := b.l - a.l;
    y := a.k - b.k;
    z := a.k*b.l - b.k*a.l;
    cdata := false;
    for n := ars downto 1 do
        begin
        for m := 1 to ars do
            if pa[m, n] > 1 then
                if cdata = false then
                    begin
                    if x*m + y*n < z then
                        begin
                        data := 1;
                        cdata := true;
                        break;
                        end;
                    if x*m + y*n > z then
                        begin
                        data := -1;
                        cdata := true;
                        break;
                        end;
                    end;
        if cdata then break;
        end;
    for n := ars downto 1 do
        for m := 1 to ars do
            if pa[m, n] > 1 then
                if data*(x*m + y*n) > data*z then exit(false)
                else if x*m + y*n = z then
                    if (m - a.k)*(m - b.k) > 0 then exit(false)
                    else if (m - a.k)*(m - b.k) = 0 then
                        if (n - a.l)*(n - b.l) > 0 then exit(false);
    exit(true);
    end;
function checkfirstedge(a, b: point; pa: a2d; ars: integer): boolean;
    var x, y, z, m, n: integer;
    begin
    x := b.l - a.l;
    y := a.k - b.k;
    z := a.k*b.l - b.k*a.l;    
    if y < 0 then
        begin
        x := -x;
        y := -y;
        z := -z;
        end;
    for n := ars downto 1 do
        for m := 1 to ars do
            if pa[m, n] > 1 then
                if x*m + y*n > z then exit(false)
                else if x*m + y*n = z then
                    if (m - a.k)*(m - b.k) > 0 then exit(false);
    exit(true);
    end;
var
    pvalue: byte;
    N, x, y, a, b, v, i: integer;
    str: ansistring;
    cells, cpoints: a2d;
    vertices: array of point;
    lexic, lexic2, cnext: boolean;
    next: point;
begin
while true do
    begin
    readln(N);
    if N = 0 then break;
    setlength(vertices, 0);
    setlength(vertices, N*N);
    setlength(cells, N + 1, N + 1);
    setlength(cpoints, N + 1, N + 1);
    for a := 0 to N do
        for b := 0 to N do
            cpoints[a, b] := 2;
    //read this shit into array
    for y := N downto 1 do
        begin
        readln(str);
        for x := 1 to N do val(str[x], cells[x, y]);
        end;
    //uncheck any points that is near a 0
    for x := 1 to N do
        for y := 1 to N do
            if cells[x, y] = 0 then
                for a := x - 1 to x do
                    for b := y - 1 to y do
                        if cpoints[a, b] = 2 then cpoints[a, b] := 0;
    //uncheck any points that is near 4 checked points, 3 checked points,
    //or between 2 checked points
    for a := 2 to N - 2 do
        for b := 2 to N - 2 do
            begin
            pvalue := 0;
            if cpoints[a, b - 1] > 0 then inc(pvalue, 2);
            if cpoints[a, b + 1] > 0 then inc(pvalue, 2);
            if cpoints[a - 1, b] > 0 then inc(pvalue, 3);
            if cpoints[a + 1, b] > 0 then inc(pvalue, 3);
            if (pvalue > 5) or (pvalue = 4) then dec(cpoints[a, b]);
            end;
    //find the lexicographically smallest point, store it in vertices[1] and
    //store the biggest pseudolexicographically smallest point in vertices[2]
    //(if it exists)
    v := 1;
    lexic := false;
    lexic2 := false;
    for a := 2 to N - 2 do
        begin
        for b := 2 to N - 2 do
            if cpoints[a, b] = 2 then
                if lexic = false then
                    begin
                    vertices[v].k := a;
                    vertices[v].l := b;
                    inc(cpoints[a, b]);
                    inc(v);
                    lexic := true;
                    end
                else
                    begin
                    vertices[v].k := a;
                    vertices[v].l := b;
                    if lexic2 = false then lexic2 := true;
                    end;
        if lexic then break;
        end;
    if lexic2 then
        begin
        inc(cpoints[vertices[v].k, vertices[v].l]);
        inc(v);
        end;
    //point the conrection (connection direction) to clockwise
    cnext := false;
    for a := N downto 1 do
        begin
        for b := 1 to N do
            if cpoints[a, b] = 2 then
                begin
                next.k := a;
                next.l := b;
                if checkfirstedge(vertices[v - 1], next, cpoints, N) then
                    begin
                    vertices[v] := next;
                    inc(cpoints[a, b]);
                    inc(v);
                    cnext := true;
                    break;
                    end;
                end;
        if cnext then break;
        end;
    //now connect everything
    while true do
        begin
        cnext := false;
        for a := N downto 1 do
            begin
            for b := 1 to N do
                if cpoints[a, b] = 2 then
                    begin
                    next.k := a;
                    next.l := b;
                    if checkedge(vertices[v - 1], next, cpoints, N) then
                        begin
                        vertices[v] := next;
                        inc(cpoints[a, b]);
                        inc(v);
                        cnext := true;
                        break;
                        end;
                    end;
            if cnext then break;
            end;
        if cnext = false then break;
        end;
    dec(v);
    //and then there's still the output
    writeln(v);
    for i := 1 to v do writeln(vertices[i].k, ' ', vertices[i].l);
    end;
end.