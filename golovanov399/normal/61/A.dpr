var
 i:integer;
 s:string;
 a,b:array[1..100] of byte;

begin
 readln(s);
 for i:=1 to length(s) do
 if s[i]='0' then a[i]:=0 else a[i]:=1;
 readln(s);
 for i:=1 to length(s) do
 if s[i]='0' then b[i]:=0 else b[i]:=1;
 for i:=1 to length(s) do
 write(a[i] xor b[i]);
end.