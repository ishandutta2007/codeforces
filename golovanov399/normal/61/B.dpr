uses
 SysUtils;

var
 n,i,j:integer;
 a,b,c,s:string;
 ar:array[1..6] of string;
begin
 readln(a);
 readln(b);
 readln(c);
 i:=1;
 while i<=length(a) do
 begin
  while (i<=length(a))and((a[i]='-')or(a[i]='_')or(a[i]=';')) do
  delete(a,i,1);
  inc(i);
 end;
 i:=1;
 while i<=length(b) do
 begin
  while (i<=length(b))and((b[i]='-')or(b[i]='_')or(b[i]=';')) do
  delete(b,i,1);
  inc(i);
 end;
 i:=1;
 while i<=length(c) do
 begin
  while (i<=length(c))and((c[i]='-')or(c[i]='_')or(c[i]=';')) do
  delete(c,i,1);
  inc(i);
 end;
 a:=lowercase(a);
 b:=lowercase(b);
 c:=lowercase(c);
 ar[1]:=a+b+c;
 ar[2]:=a+c+b;
 ar[3]:=b+a+c;
 ar[4]:=b+c+a;
 ar[5]:=c+a+b;
 ar[6]:=c+b+a;
 readln(n);
 for j:=1 to n do
 begin
  readln(s);
  i:=1;
  while i<=length(s) do
  begin
   while (i<=length(s))and((s[i]='-')or(s[i]='_')or(s[i]=';')) do
   delete(s,i,1);
   inc(i);
  end;
  s:=lowercase(s);
  if (s=ar[1])or(s=ar[2])or(s=ar[3])or(s=ar[4])or(s=ar[5])or(s=ar[6]) then
  writeln('ACC') else
  writeln('WA');
 end;
end.