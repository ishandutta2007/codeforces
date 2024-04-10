uses math;

const MaxMN = 1000;

var n, m, ans: longint;
    a: array[1 .. MaxMN, 1 .. MaxMN] of longint;
    f: array[1 .. 4, 0 .. MaxMN + 1, 0 .. MaxMN + 1] of longint;

procedure input;
var i, j: longint;
begin
    fillchar(a, sizeof(a), 0);
    readln(n, m);
    for i := 1 to n do begin
        for j := 1 to m do
            read(a[i,j]);
        readln;
    end;
end;

procedure run;
var i, j: longint;
begin
    fillchar(f, sizeof(f), 0);
    for i := 0 to n-1 do
        for j := 0 to m-1 do begin
            f[1,i+1,j+1] := max(f[1,i,j+1], f[1,i+1,j]) + a[i+1,j+1];
            f[2,n-i,j+1] := max(f[2,n-i+1,j+1], f[2,n-i,j]) + a[n-i,j+1];
            f[3,i+1,m-j] := max(f[3,i,m-j], f[3,i+1,m-j+1]) + a[i+1,m-j];
            f[4,n-i,m-j] := max(f[4,n-i+1,m-j], f[4,n-i,m-j+1]) + a[n-i,m-j];
        end;
    ans := 0;
    for i := 2 to n - 1 do
        for j := 2 to m - 1 do
            ans := max(ans,max(f[1,i-1,j]+f[2,i,j-1]+f[3,i,j+1]+f[4,i+1,j],f[1,i,j-1]+f[2,i+1,j]+f[3,i-1,j]+f[4,i,j+1]));
end;

procedure output;
begin
    write(ans);
end;

begin
    input;
    run;
    output;
end.