var
  x,y,a,b,p,q,l,r,ans:int64;
begin
  readln(x,y,a,b,p,q);ans:=100000000;
  if ((a=1)or(a=x))and((b=1)or(b=y)) then begin
    writeln(0);halt;
  end;
  if (p>=x)or(q>=y) then begin
    writeln('Poor Inna and pony!');halt;
  end;
  if ((a-1) mod p=0) then begin
    l:=(a-1) div p;
    if ((b-1) mod q=0) then begin
      r:=(b-1) div q;
      if l and 1=r and 1 then
        if l>r then begin
          if l<ans then ans:=l
        end else begin
          if r<ans then ans:=r;
        end;
    end;
    if ((y-b) mod q=0) then begin
      r:=(y-b) div q;
      if l and 1=r and 1 then
        if l>r then begin
          if l<ans then ans:=l
        end else begin
          if r<ans then ans:=r;
        end;
    end;
  end;
  if ((x-a) mod p=0) then begin
    l:=(x-a) div p;
    if ((b-1) mod q=0) then begin
      r:=(b-1) div q;
      if l and 1=r and 1 then
        if l>r then begin
          if l<ans then ans:=l
        end else begin
          if r<ans then ans:=r;
        end;
    end;
    if ((y-b) mod q=0) then begin
      r:=(y-b) div q;
      if l and 1=r and 1 then
        if l>r then begin
          if l<ans then ans:=l
        end else begin
          if r<ans then ans:=r;
        end;
    end;
  end;
  if ans=100000000 then writeln('Poor Inna and pony!') else writeln(ans);
end.