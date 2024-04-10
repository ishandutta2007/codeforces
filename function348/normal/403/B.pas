var
        n,m,i,j,k,x,tot,num,ans:longint;
        a,p,q,r,v:array[1..50000]of longint;
function gcd(a,b:longint):longint;
begin
        if b=0 then exit(a)
               else exit(gcd(b,a mod b));
end;
function f(n:longint):longint;
var i,cnt:longint;
begin
        cnt:=0;
        for i:=1 to num do
        begin
                if n<p[i] then break;
                while n mod p[i]=0 do
                begin
                        n:=n div p[i];
                        cnt:=cnt+q[i];
                end;
        end;
        if n=1 then exit(cnt);
        for i:=1 to tot do
        if n=r[i] then exit(cnt-1);
        exit(cnt+1);
end;

begin
        readln(n,m);
        for i:=2 to 178 do
        if v[i]=0 then
        for j:=2 to 32000 div i do
        v[i*j]:=10;
        for i:=1 to n do read(a[i]);
        for i:=1 to m do
        begin
                read(x);
                if x<=32000 then v[x]:=-1
                else
                begin
                        inc(tot);r[tot]:=x;
                end;
        end;
        for i:=2 to 32000 do
        if v[i]<>10 then
        begin
                inc(num);p[num]:=i;
                if v[i]=0 then q[num]:=1
                          else q[num]:=-1;
        end;
        for i:=n downto 1 do
        begin
                k:=a[1];
                for j:=2 to i do k:=gcd(k,a[j]);
                if f(k)<0 then for j:=1 to i do a[j]:=a[j] div k;
        end;
        ans:=0;
        for i:=1 to n do ans:=ans+f(a[i]);
        writeln(ans);
end.