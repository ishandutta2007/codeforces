var s:array[1..100] of string;
    n,t,i,j:longint;
    ss:string;
    f:boolean;
begin
  readln(n);t:=0;f:=false;
  for i:=1 to n do
    begin
      readln(ss);f:=false;
      for j:=1 to t do
        if s[j]=ss then
          begin
            f:=true;break;
          end;
      if not f then
        begin
          inc(t);s[t]:=ss;
        end;
    end;
  writeln(t);
end.