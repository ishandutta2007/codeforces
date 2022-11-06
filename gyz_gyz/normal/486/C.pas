var
  s:ansistring;
  n,m,i,x,y,p,q,ans:longint;
begin
  readln(n,m);
  readln(s);
  if m>n shr 1 then m:=n+1-m;
  for i:=1 to n shr 1 do
    if s[i]<>s[n+1-i] then begin
      if x=0 then x:=i;y:=i;
      if s[i]<s[n+1-i] then begin
        p:=ord(s[i])-48;q:=ord(s[n+1-i])-48;
      end else begin
        q:=ord(s[i])-48;p:=ord(s[n+1-i])-48;
      end;
      if q-p<p+26-q then inc(ans,q-p) else inc(ans,p+26-q);
    end;
  if y=0 then begin
    writeln(0);halt;
  end;
  inc(ans,y-x);
  if abs(x-m)<abs(y-m) then inc(ans,abs(x-m)) else inc(ans,abs(y-m));
  writeln(ans);
end.