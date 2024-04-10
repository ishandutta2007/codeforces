const r='rps';
      rr='FMS';
var a:array[0..2] of longint;
    s:string;
    i:longint;

begin
     for i:=0 to 2 do
     begin
          readln(s);
          a[i]:=pos(s[1],r)-1;
     end;
     for i:=0 to 2 do
         if (a[(i+1) mod 3]=a[(i+2) mod 3]) and ((a[(i+1) mod 3]+1) mod 3=a[i]) then
         begin
              writeln(rr[i+1]); exit;
         end;
     writeln('?');
end.