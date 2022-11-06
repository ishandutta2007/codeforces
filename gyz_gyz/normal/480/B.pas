var
  a:array[1..100000]of int64;
  n,l,x,y,t,c1,c2,c3,s:int64;
  i:longint;
begin
  readln(n,l,x,y);
  for i:=1 to n do read(a[i]);
  s:=1;
  for i:=1 to n do begin
    while a[i]-a[s]>x do inc(s);
    if a[i]-a[s]=x then begin
      c1:=1;break;
    end;
  end;
  s:=1;
  for i:=1 to n do begin
    while a[i]-a[s]>y do inc(s);
    if a[i]-a[s]=y then begin
      c2:=1;break;
    end;
  end;
  if c1+c2=0 then begin
    s:=1;c3:=0;
    for i:=1 to n do begin
      while a[i]-a[s]>x+y do inc(s);
      if a[i]-a[s]=x+y then begin
        c3:=s;break;
      end;
    end;
    if c3>0 then begin
      writeln(1);writeln(a[c3]+x);halt;
    end;
    s:=1;c3:=0;
    for i:=1 to n do begin
      while a[i]-a[s]>y-x do inc(s);
      if a[i]-a[s]=y-x then begin
        c3:=s;break;
      end;
    end;
    if (c3>0)and(a[c3]+y<=l) then begin
      writeln(1);writeln(a[c3]+y);halt;
    end;
    for i:=1 to n do begin
      while a[i]-a[s]>y-x do inc(s);
      if a[i]-a[s]=y-x then c3:=s;
    end;
    if (c3>0)and(a[c3]-x>=0) then begin
      writeln(1);writeln(a[c3]-x);halt;
    end;
    writeln(2);writeln(x,' ',y);halt;
  end;
  writeln(2-c1-c2);
  if c1=0 then writeln(x);
  if c2=0 then writeln(y);
end.