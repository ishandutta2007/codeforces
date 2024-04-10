var
  s:array[0..100000,1..26]of longint;
  a,b:array[0..100000]of boolean;
  n,m,i,j,k,p,t:longint;
  st:ansistring;
procedure f(x:longint);
var i,u:longint;
begin
  u:=0;
  for i:=1 to 26 do
    if s[x,i]<>0 then begin
      f(s[x,i]);u:=1;
    end;
  if u=0 then b[x]:=true;
  for i:=1 to 26 do
    if s[x,i]<>0 then
      if not(b[s[x,i]]) then b[x]:=true;
  for i:=1 to 26 do
    if s[x,i]<>0 then
      if not(a[s[x,i]]) then a[x]:=true;
end;
begin
  readln(n,m);
  for i:=1 to n do begin
    readln(st);k:=0;
    for j:=1 to length(st) do begin
      t:=ord(st[j])-96;
      if s[k,t]=0 then begin
        inc(p);s[k,t]:=p;
      end;
      k:=s[k,t];
    end;
  end;
  f(0);
  if a[0] and b[0] then begin
    writeln('First');exit;
  end;
  if not(a[0]) then begin
    writeln('Second');exit;
  end;
  if m and 1=0 then writeln('Second') else writeln('First');
end.