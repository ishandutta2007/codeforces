var n,i,j: longint;
    k,sp,sl: array [1..100] of longint;
    s: array [1..100,1..100] of char; 

begin
  readln (n);
  for i:=1 to n do 
  begin
    readln (k[i]);
    for j:=1 to k[i] do read (s[i,j]);
  end;
  for i:=1 to n do
  begin
    if k[i]=1 then writeln ('0') else
    begin
      sl[i]:=0;
      j:=1;
      while (s[i,j]<>'>') and (j<=k[i]-1)  do
      begin
        j:=j+1;
      end;
      sl[i]:=j-1;
      sp[i]:=0;
      j:=k[i];
      while (s[i,j]<>'<') and (j>=2) do
      begin
        j:=j-1;
      end;
      sp[i]:=k[i]-j;
      writeln (min(sp[i],sl[i]));
    end;
  end;
end.