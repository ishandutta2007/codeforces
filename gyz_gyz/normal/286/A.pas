var
  a:array[1..100000]of longint;
  n,i,x,s,r:longint;
begin
  readln(n);
  for i:=1 to n do a[i]:=i;
  if n=1 then begin
    writeln(1);exit;
  end;
  for s:=1 to n div 2 do
    if a[s]=s then begin
      inc(r);i:=n div 2+1-r;a[s]:=n div 2+1-r;x:=n-s+1;
      while i<>s do begin
        a[i]:=x;
        x:=n-i+1;
        i:=a[i];
      end;
    end;
  for i:=1 to n div 2 do
    if a[i]=i then begin
      writeln(-1);exit;
    end;
  for i:=1 to n do write(a[i],' ');
  writeln;
end.