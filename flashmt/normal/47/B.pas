const r='><';
var b,c,d:char;
    a:array['A'..'C','A'..'C'] of longint;
    e:array['A'..'C'] of longint;
    f:array[-2..2] of char;
    g:array[-2..2] of longint;
    i:longint;

begin
     for i:=1 to 3 do
     begin
          readln(b,d,c);
          a[b,c]:=pos(d,r);
          a[c,b]:=3-a[b,c];
     end;
     for b:='A' to 'B' do
      for c:=chr(ord(b)+1) to 'C' do
        if a[b,c]=2 then a[b,c]:=-1
        else a[c,b]:=-1;
     for b:='A' to 'C' do
         for c:='A' to 'C' do
             if b<>c then e[b]:=e[b]+a[b,c];
     fillchar(g,sizeof(g),0);
     for b:='A' to 'C' do
     begin
          f[e[b]]:=b;
          inc(g[e[b]]);
     end;
     if g[0]=3 then writeln('Impossible')
     else writeln(f[-2],f[0],f[2]);
end.