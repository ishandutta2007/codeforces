var n,x:longint;
begin
  readln(n);x:=5;
  while x<n do begin
    dec(n,x);x:=x shl 1;
  end;
  case (n-1) div (x div 5)+1 of
    1:writeln('Sheldon');
    2:writeln('Leonard');
    3:writeln('Penny');
    4:writeln('Rajesh');
    5:writeln('Howard');
  end;
end.