var
  n,m,mi,mx,l1,l2:longint;
  an1,an2:real;
begin
  readln(n,m);
  if n>m then mx:=n else mx:=m;
  if n>m then mi:=m else mi:=n;
  l1:=n*n+m*m;l2:=(mi-1)*(mi-1)+mx*mx;
  an1:=sqrt(l1)*2+mx;an2:=sqrt(l2)*2+sqrt(l1);
  if an1<an2 then begin
    if (n>m)and(m>0)or(n=0) then begin
      writeln('0 1');
      writeln(n,' ',m);
      writeln('0 0');
      writeln(n,' ',m-1);
    end else begin
      writeln('1 0');
      writeln(n,' ',m);
      writeln('0 0');
      writeln(n-1,' ',m);
    end;
  end else begin
    writeln('0 0');
    writeln(n,' ',m);
    if n>m then begin
      writeln('0 ',m);
      writeln(n,' 0');
    end else begin
      writeln(n,' 0');
      writeln('0 ',m);
    end;
  end;
end.