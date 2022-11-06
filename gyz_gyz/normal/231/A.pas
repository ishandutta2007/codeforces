var
  n,i,a1,a2,a3,ans:longint;
begin
  readln(n);
  for i:=1 to n do begin
    readln(a1,a2,a3);
    if a1+a2+a3>=2 then inc(ans);
  end;
  writeln(ans);
end.