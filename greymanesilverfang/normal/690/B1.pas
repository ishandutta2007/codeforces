var
N, a, b, left, right, upper, lower: integer;
str: ansistring;
cell: byte;
cells: array of array of byte;
check, cleft, cright, cupper, clower: boolean; //check left, etc.
begin
//read the whole thing into array
readln(N);
setlength(cells, N + 1, N + 1);
for a := 1 to N do
    begin
    readln(str);
    for b := 1 to N do
        begin
        val(str[b], cell);
        cells[a, b] := cell;
        end;
    end;
//check if there is any 3
for a := 1 to N do
    for b := 1 to N do
        if cells[a, b] = 3 then
            begin
            writeln('No');
            exit;
            end;
//check if there is at least a 4
check := false;
for a := 1 to N do
    begin
    for b := 1 to N do
        if cells[a, b] = 4 then
            begin
            check := true;
            break;
            end;
    if check = true then break;
    end;
if check = false then
    begin
    writeln('No');
    exit;
    end;
//find the leftmost, rightmost, uppermost and lowermost 4
cleft := false;
cright := false;
cupper := false;
clower := false;
for b := 1 to N do
    begin
    for a := 1 to N do
        if cells[a, b] = 4 then
            begin
            left := b;
            cleft := true;
            break;
            end;
    if cleft = true then break;
    end;
for b := N downto 1 do
    begin
    for a := 1 to N do
        if cells[a, b] = 4 then
            begin
            right := b;
            cright := true;
            break;
            end;
    if cright = true then break;
    end;
for a := 1 to N do
    begin
    for b := 1 to N do
        if cells[a, b] = 4 then
            begin
            upper := a;
            cupper := true;
            break;
            end;
    if cupper = true then break;
    end;
for a := N downto 1 do
    begin
    for b := 1 to N do
        if cells[a, b] = 4 then
            begin
            lower := a;
            clower := true;
            break;
            end;
    if clower = true then break;
    end;
//check if anything in that range is a 4
for a := upper to lower do
    for b := left to right do
        if cells[a, b] < 4 then
            begin
            writeln('No');
            exit;
            end;
//check if the 2's are where they're supposed to be
for a := upper to lower do
    for b := 1 to N do
        if (b = left - 1) or (b = right + 1) then
            if cells[a, b] < 2 then
                begin
                writeln('No');
                exit;
                end;
for b := left to right do
    for a := 1 to N do
        if (a = upper - 1) or (a = lower + 1) then
            if cells[a, b] < 2 then
                begin
                writeln('No');
                exit;
                end;
//check if the 1's are where they're supposed to be
for a := 1 to N do
    for b := 1 to N do
        if ((a = upper - 1) or (a = lower + 1)) and ((b = left - 1) or (b = right + 1)) then
            if cells[a, b] <> 1 then
                begin
                writeln('No');
                exit;
                end;
//check if everything else is 0
for a := 1 to N do
    for b := 1 to N do
        if ((a < upper - 1) or (a > lower + 1)) or ((b < left - 1) or (b > right + 1)) then
            if cells[a, b] > 0 then
                begin
                writeln('No');
                exit;
                end;
//if it hadn't been terminated early then it's a rectangle =))
writeln('Yes');
end.