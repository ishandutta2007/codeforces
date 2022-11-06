var
  mp:array[0..2000,0..2000]of int64;
  a,b:array[0..3999]of int64;
  n,m,an1,an2,x1,y1,x2,y2,g,h:int64;
  i,j:longint;
begin
  readln(n);an1:=-1;an2:=-1;
  for i:=1 to n do
    for j:=1 to n do begin
      read(mp[i,j]);
      inc(a[i+j-1],mp[i,j]);
      inc(b[i-j+n],mp[i,j]);
    end;
  for i:=1 to n*2-1 do
    for j:=1 to n*2-1 do
      if i and 1 xor j and 1<>n and 1 then
        if i and 1=1 then begin
          g:=(i+j-n+1) shr 1;h:=(i-j+n+1) shr 1;
          if (g<1)or(g>n)or(h<1)or(h>n) then continue;
          if a[i]+b[j]-mp[g,h]>an1 then begin
            x1:=g;y1:=h;an1:=a[i]+b[j]-mp[g,h];
          end;
        end else begin
          g:=(i+j-n+1) shr 1;h:=(i-j+n+1) shr 1;
          if (g<1)or(g>n)or(h<1)or(h>n) then continue;
          if a[i]+b[j]-mp[g,h]>an2 then begin
            x2:=g;y2:=h;an2:=a[i]+b[j]-mp[g,h];
          end;
        end;
  writeln(an1+an2);
  writeln(x1,' ',y1,' ',x2,' ',y2);
end.