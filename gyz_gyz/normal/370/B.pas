var
  a:array[1..100,1..100]of longint;
  b:Array[1..100]of longint;
  n,i,j,k,x,u:longint;
begin
  readln(n);
  for i:=1 to n do begin
    read(b[i]);
    for j:=1 to b[i] do begin
      read(x);a[i,x]:=1;
    end;
  end;
  for i:=1 to n do begin
    u:=0;
    for j:=1 to n do begin
      if i=j then continue;
      x:=0;
      for k:=1 to 100 do
        if a[j,k]-a[i,k]>0 then x:=1;
      if x=0 then begin
        writeln('NO');u:=1;break;
      end;
    end;
    if u=0 then writeln('YES');
  end;
end.