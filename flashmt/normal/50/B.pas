var s:ansistring;
    a:array['0'..'z'] of longint;
    c:char;
    re:int64;
    i:longint;

begin
     fillchar(a,sizeof(a),0);
     readln(s);
     for i:=1 to length(s) do inc(a[s[i]]);
     re:=0;
     for c:='0' to '9' do re:=re+int64(a[c])*a[c];
     for c:='a' to 'z' do re:=re+int64(a[c])*a[c];
     writeln(re);
end.