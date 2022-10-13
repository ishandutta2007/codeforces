var s:string;
    a:array[1..3] of longint;
    i,j:longint;
    d:array['a'..'z'] of longint;

begin
     fillchar(d,sizeof(d),0);
     d['a']:=1; d['e']:=1; d['i']:=1; d['o']:=1; d['u']:=1;
     for j:=1 to 3 do
     begin
          readln(s);
          for i:=1 to length(s) do
             if (s[i]<>' ') and (d[s[i]]=1) then inc(a[j]);
     end;
     if (a[1]=5) and (a[2]=7) and (a[3]=5) then writeln('YES')
     else writeln('NO');
end.