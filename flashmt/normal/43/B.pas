var s,t:string;
    a:array['A'..'z'] of longint;
    i:longint;
    c:char;

begin
     fillchar(a,sizeof(a),0);
     readln(s);
     readln(t);
     for i:=1 to length(s) do
         if s[i]<>' ' then inc(a[s[i]]);
     for i:=1 to length(t) do
         if t[i]<>' ' then dec(a[t[i]]);
     for c:='A' to 'z' do
         if a[c]<0 then
         begin
              writeln('NO');
              halt;
         end;
     writeln('YES');
end.