var n,i,left,right: longint;
    s: array [1..200000] of char;
    q,a,b: array [1..200000] of longint;
    
function min(a,b:longint):longint;
begin
  min:=b;
  if a<b then min:=a;
end;

begin
  readln (n);
  for i:=1 to n do readln (s[i], q[i]);
  left:=100000;
  right:=100001;
  for i:=1 to n do
  begin
    if s[i]='L' then 
    begin
      a[q[i]]:=left;
      left:=left-1;
    end;
    if s[i]='R' then
    begin
      a[q[i]]:=right;
      right:=right+1;
    end;
    if s[i]='?' then writeln (min (a[q[i]]-left-1, right-1-a[q[i]]));
  end;
end.