var n,i,j,l,m,k,z:longint;
    s:ansistring;
    a,f:array[0..10011] of longint;

begin
     readln(n);
     readln(s);
     f[0]:=0; a[0]:=-1;
     l:=length(s); m:=0;
     for i:=1 to l do
        if (s[i]='.') or (s[i]='?') or (s[i]='!') then
        begin
             if i-a[m]-1>n then
             begin
                  writeln('Impossible');
                  halt;
             end;
             j:=1; k:=m;
             while (k>=0) and (i-1-a[k]<=n) do
             begin
                  z:=k; dec(k);
             end;
             inc(m);
             f[m]:=f[z]+1; a[m]:=i;
        end;
     writeln(f[m]);
end.