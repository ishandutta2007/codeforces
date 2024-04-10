var
f1,f:array [1..1000,1..2] of longint;
i,j,m,n,p,k,p1,p2,p3,t:longint;
a,b:longint;
function gcd(a,b:longint):longint;
  begin
    if (b=0) then exit(a);
    exit(gcd(b,a mod b));
  end;
begin
readln(a,b);
for i:=1 to a-1 do
  if (trunc(sqrt(sqr(a)-sqr(i)))=sqrt(sqr(a)-sqr(i))) then
      begin inc(p1); f[p1][1]:=i; f[p1][2]:=trunc(sqrt(sqr(a)-sqr(i))); end;
for i:=1 to b-1 do
  if (trunc(sqrt(sqr(b)-sqr(i)))=sqrt(sqr(b)-sqr(i))) then
      begin inc(p2); f1[p2][1]:=i; f1[p2][2]:=trunc(sqrt(sqr(b)-sqr(i))); end;
for i:=1 to p1 do
  for j:=1 to p2 do
    begin
     p:=gcd(f[i][1],f[i][2]);
     p3:=gcd(f1[j][1],f1[j][2]);
      if ((f[i][1] div p=f1[j][2] div p3) and (f[i][2] div p=f1[j][1
      ] div p3)) then
begin        if (f[i][2]=f1[j][2]) then continue;
      writeln('YES');
       writeln('0 0');
         if (f1[j][2]=f[i][2]) then
           begin if (f1[j][1]<>f1[j][2]) then begin t:=f1[j][1]; f1[j][1]:=f1[j][2]; f1[j][2]:=t; end
           else begin t:=f[i][1]; f[i][1]:=f[i][2]; f[i][2]:=t; end;
           end;
     writeln(-f[i][1],' ',-f[i][2]);
     writeln(f1[j][1],' ',-f1[j][2]);
     exit;
 end;
end;
writeln('NO');
end.