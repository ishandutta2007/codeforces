uses math;
var n,a,b,i,j,p,k:longint;
    s:string;
    f:array[0..200,0..200] of boolean;
    tr:array[0..200,0..200] of longint;
    c:array[0..200] of longint;
begin
     readln(k,a,b);
     readln(s);
     n:=length(s);
     fillchar(f,sizeof(f),false);
     f[0,0]:=true;
     for i:=a to n do
       for j:=1 to k do
         for p:=a to min(b,i) do
             if f[i-p,j-1] then
             begin
                  f[i,j]:=true;
                  tr[i,j]:=i-p;
             end;
     if f[n,k] then
     begin
          c[k]:=n; c[0]:=0;
          for i:=k-1 downto 1 do
          begin
               n:=tr[n,i+1];
               c[i]:=n;
          end;
          for i:=1 to k do
          begin
               for j:=c[i-1]+1 to c[i] do write(s[j]);
               writeln;
          end;
     end
     else writeln('No solution');
end.