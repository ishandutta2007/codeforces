var
  t,n,m,p,q,tp,a1,a2,a3,a4:int64;
  op:longint;
begin
  readln(t);
  for op:=1 to t do begin
    readln(n,m,p,q);
    if n mod 3<>0 then begin
      writeln('no');continue;
    end;
    if p<q then begin
      tp:=p;p:=q;q:=tp;
    end;
    a1:=p+q;a2:=p*2-q;a3:=p*2+q;a4:=p+q*2;
    if (a1<=n-m)and(a2<=m)and((m-a2) mod 3=0) then begin
      writeln('yes');continue;
    end;
    if (a2<=n-m)and(a1<=m)and((m-a1) mod 3=0) then begin
      writeln('yes');continue;
    end;
    if (a3<=n-m)and(a4<=m)and((m-a4) mod 3=0) then begin
      writeln('yes');continue;
    end;
    if (a4<=n-m)and(a3<=m)and((m-a3) mod 3=0) then begin
      writeln('yes');continue;
    end;
    writeln('no');
  end;
end.