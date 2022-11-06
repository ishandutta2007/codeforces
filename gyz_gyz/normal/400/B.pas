var
  a:array[1..1000]of longint;
  s:ansistring;
  n,m,p1,p2,i,ans:longint;
begin
  readln(n,m);
  for i:=1 to n do begin
    readln(s);
    p1:=pos('G',s);
    p2:=pos('S',s);
    if p1>=p2 then begin
      writeln(-1);halt;
    end;
    a[p2-p1]:=1;
  end;
  for i:=1 to m do
    if a[i]=1 then inc(ans);
  writeln(ans);
end.