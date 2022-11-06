var
  f:array[1..2000000,0..1]of int64;
  a,nt:array[1..2000000]of int64;
  n,i:longint;
  x,ans:int64;
begin
  readln(n);
  if n=1 then begin
    writeln(0);halt;
  end;
  for i:=1 to n do read(a[i]);
  for i:=2 to n do inc(ans,abs(a[i]-a[i-1]));
  x:=1;
  for i:=2 to n-1 do begin
    if (a[i]<a[i-1])and(a[i]<=a[i+1]) then begin
      nt[x]:=i;x:=i;
    end;
    if (a[i]>a[i-1])and(a[i]>=a[i+1]) then begin
      nt[x]:=i;x:=i;
    end;
  end;
  fillchar(f,sizeof(f),$7f);
  nt[x]:=n;f[1,1]:=abs(a[2]-a[1]);f[1,0]:=0;i:=1;
  while nt[i]<n do begin
    if nt[i]-i>1 then begin
      if f[i,0]<f[i,1] then
      f[nt[i],0]:=f[i,0]
      else f[nt[i],0]:=f[i,1];
      inc(f[nt[i],0],abs(a[nt[i]]-a[nt[i]-1]));
      if f[i,0]<f[i,1] then
      f[nt[i],1]:=f[i,0]
      else f[nt[i],1]:=f[i,1];
      inc(f[nt[i],1],abs(a[nt[i]]-a[nt[i]+1]));
    end else begin
      f[nt[i],0]:=f[i,1];
      if f[i,0]<f[i,1] then
      f[nt[i],1]:=f[i,0]
      else f[nt[i],1]:=f[i,1];
      inc(f[nt[i],1],abs(a[nt[i]]-a[nt[i]+1]));
    end;
    i:=nt[i];
  end;
  if f[i,0]<f[i,1] then dec(ans,f[i,0]) else dec(ans,f[i,1]);
  writeln(ans);
end.