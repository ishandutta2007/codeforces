var
  a:array[0..200000]of int64;
  gg,jj,g,t,w,f,z,j,s,p,pp,u:int64;
procedure wr;inline;
begin
  writeln(p+(j-g-1) div s+1);halt;
end;
begin
  readln(g,w,z,f,j);
  s:=1;t:=1;
  if g>=j then begin
    writeln(0);exit;
  end;
  while true do begin
    if g>=j-w div f*s then wr;
    dec(g,t);dec(j,w div f*s+s);
    inc(p,w div f+1);w:=w mod f+z-f;
    if a[w]=1 then begin
      gg:=gg-g;jj:=jj-j;
      pp:=(j-g) div (jj-gg)-1;
      dec(j,pp*jj);dec(g,pp*gg);
      inc(p,(p-u)*pp);break;
    end;
    if u=0 then begin
      u:=p;jj:=j;gg:=g;
    end;
    a[w]:=1;
  end;
  if g>=j then begin
    writeln(p);exit;
  end;
  while true do begin
    if g>=j-w div f*s then wr;
    dec(g,t);dec(j,w div f*s+s);
    inc(p,w div f+1);w:=w mod f+z-f;
  end;
  writeln(p);
end.