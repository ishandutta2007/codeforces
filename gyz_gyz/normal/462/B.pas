var
  a,b:array[0..25]of int64;
  n,i,j:longint;
  c:char;
  ans,mx,x,k:int64;
begin
  readln(n,k);
  for i:=1 to n do begin
    read(c);inc(a[ord(c)-65]);
  end;
  for i:=0 to 25 do begin
    mx:=0;
    for j:=0 to 25 do
      if (b[j]=0)and(a[j]>mx) then begin
        mx:=a[j];x:=j;
      end;
    b[x]:=1;
    if mx<k then begin
      inc(ans,mx*mx);dec(k,mx);
    end else begin
      inc(ans,k*k);break;
    end;
  end;
  writeln(ans);
end.