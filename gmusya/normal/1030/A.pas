var i,n,k: longint;
    a: array [1..100] of longint;
begin
readln (n);
k:=0;
for i:=1 to n do read (a[i]);
for i:=1 to n do if a[i]=1 then k:=1;
if k=0 then writeln ('EASY') else writeln ('HARD');
end.