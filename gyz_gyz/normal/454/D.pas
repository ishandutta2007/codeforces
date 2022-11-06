const
  ct:array[1..16]of longint=(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53);
var
  a,g:array[0..100,0..65535]of longint;
  tt:array[1..58]of longint;
  p:array[0..65535,1..58]of longint;
  q:array[0..65535]of longint;
  b,wt:array[1..100]of longint;
  tp:array[1..16]of longint;
  n,i,j,k,an1,an2:longint;
begin
  readln(n);
  for i:=1 to n do
    for j:=0 to 65535 do a[i,j]:=3000;
  for i:=1 to n do read(b[i]);
  for i:=1 to 58 do
    for j:=1 to 16 do begin
      tt[i]:=tt[i] shl 1;
      if i mod ct[j]=0 then inc(tt[i]);
    end;
  for i:=0 to 65535 do
    for j:=1 to 58 do
      if tt[j] and i=0 then begin
        inc(q[i]);p[i,q[i]]:=j;
      end;
  for i:=1 to n do
    for j:=0 to 65535 do
      for k:=1 to q[j] do
        if a[i-1,j]+abs(p[j,k]-b[i])<a[i,j or tt[p[j,k]]] then begin
          a[i,j or tt[p[j,k]]]:=a[i-1,j]+abs(p[j,k]-b[i]);
          g[i,j or tt[p[j,k]]]:=p[j,k];
        end;
  an1:=3000;
  for i:=0 to 65535 do
    if a[n,i]<an1 then begin
      an1:=a[n,i];an2:=i;
    end;
  for i:=n downto 1 do begin
    wt[i]:=g[i,an2];
    an2:=an2 xor tt[wt[i]];
  end;
  for i:=1 to n do write(wt[i],' ');
  writeln;
end.