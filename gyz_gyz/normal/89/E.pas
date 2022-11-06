var
  a:array[0..2000]of longint;
  n,t,i,j,k,u,p:longint;
procedure f(x:longint);
var i,j:longint;
begin
  while a[x]>=2 do begin
    i:=x;
    while true do begin
      if a[i]<2 then break;
      dec(a[i]);dec(p);inc(i);
    end;
    for j:=x+1 to i-1 do write('RA');
    for j:=x to i-1 do write('L');
    write('AARA');
  end;
end;
begin
  readln(n);
  for i:=1 to n do begin
    read(a[i]);inc(p,a[i]);
  end;
  i:=0;write('A');
  while true do begin
    while a[i]=0 do begin
      inc(i);write('RA');
    end;
    j:=i;u:=0;t:=i;f(i);
    dec(a[i]);dec(p);
    while true do begin
      inc(i);
      if a[i]=0 then inc(u)
      else begin
        for k:=j+1 to i do begin
          write('RA');f(k);
        end;
        dec(a[i]);dec(p);j:=i;u:=0;
      end;
      if (u>(j-t)*2+4)or(p=0) then break;
    end;
    for k:=t to j do write('L');
    write('A');i:=j-1;
    if p=0 then break;
    write('A');
  end;
  writeln;
end.