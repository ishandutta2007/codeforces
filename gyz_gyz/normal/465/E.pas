const mx:int64=1000000007;
var
  s:ansistring;
  n,i,j:longint;
  al,r,x:int64;
  p,t:array[0..9]of int64;
  a:array[1..100000]of longint;
  b:array[1..100000]of ansistring;
  ch:char;
begin
  readln(s);readln(n);
  for i:=1 to n do begin
    read(ch);a[i]:=ord(ch)-48;
    read(ch);read(ch);readln(b[i]);
  end;
  for i:=0 to 9 do begin
    p[i]:=i;t[i]:=10;
  end;
  for i:=n downto 1 do begin
    r:=0;x:=1;
    for j:=length(b[i]) downto 1 do begin
      r:=(r+p[ord(b[i,j])-48]*x) mod mx;
      x:=x*t[ord(b[i,j])-48] mod mx;
    end;
    p[a[i]]:=r;t[a[i]]:=x;
  end;
  r:=0;x:=1;
  for i:=length(s) downto 1 do begin
    r:=(r+p[ord(s[i])-48]*x) mod mx;
    x:=x*t[ord(s[i])-48] mod mx;
  end;
  writeln(r);
end.