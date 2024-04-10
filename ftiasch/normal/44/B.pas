var n,a,b,c,i,j,s:longint;
function min(a,b:longint):longint;
  begin
    if a<b then min:=a else min:=b;
  end;
begin
  readln(n,a,b,c);n:=n+n;
  for i:=0 to min(n shr 2,c) do
    for j:=0 to min(b,(n-i shl 2) shr 1) do
      if n-i shl 2-j shl 1<=a then inc(s);
  writeln(s);
end.