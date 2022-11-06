var
  s:ansistring;
  n,i,j,l,p,ans:longint;
begin
  readln(s);l:=length(s);
  while true do begin
    p:=pos('bear',s);
    if p=0 then break;
    inc(ans,l-p-2);
    delete(s,1,1);dec(l);
  end;
  writeln(ans);
end.