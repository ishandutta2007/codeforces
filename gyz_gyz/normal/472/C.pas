var
  s1,s2:array[1..100000]of string;
  n,i,x:longint;
  st:string;
begin
  readln(n);
  for i:=1 to n do begin
    readln(st);
    x:=pos(' ',st);
    s1[i]:=copy(st,1,x-1);
    s2[i]:=copy(st,x+1,length(st)-x);
    if s1[i]>s2[i] then begin
      st:=s1[i];s1[i]:=s2[i];s2[i]:=st;
    end;
  end;
  st:='';
  for i:=1 to n do begin
    read(x);
    if s2[x]<st then begin
      writeln('NO');halt;
    end;
    if s1[x]>st then st:=s1[x] else st:=s2[x];
  end;
  writeln('YES');
end.