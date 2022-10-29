uses math;

var n, i: longint;
    x, y: array[0..1001] of int64;
    ans: double;

begin
    readln(n);
    for i := 1 to n do
        readln(x[i], y[i]);
    x[0] := x[n];
    y[0] := y[n];
    x[n+1] := x[1];
    y[n+1] := y[1];
    ans := high(int64);
    for i := 1 to n do
        ans := min(ans, ((x[i]-x[i-1])*(y[i]-y[i+1])-(y[i]-y[i-1])*(x[i]-x[i+1]))/sqrt(sqr(x[i+1]-x[i-1])+sqr(y[i+1]-y[i-1]))/2);
    write(ans : 0 : 8);
end.