var
  w1,w2:array[1..10000]of longint;
  n,m,k,i,j,s,ans:longint;
begin
  readln(n,m,k);s:=2;j:=1;
  for i:=1 to k do begin
    if (j>m)or(s-j<1) then begin
      inc(s);j:=1;
    end;
    while s-j>n do inc(j);
    inc(ans,s-1);w1[i]:=j;w2[i]:=s-j;inc(j);
  end;
  writeln(ans);
  for i:=k downto 1 do begin
    j:=1;
    while j<w1[i] do begin
      write('(1,',j,') ');inc(j);
    end;
    j:=1;
    while j<=w2[i] do begin
      write('(',j,',',w1[i],') ');inc(j);
    end;
    writeln;
  end;
end.