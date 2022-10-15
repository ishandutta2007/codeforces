const
 maxN = 1000 + 100;
 maxPhoto = 1000000 + 100;
type
 mass = array [1 .. maxN] of longint;
 photoMass = array [1 .. maxPhoto] of longint;
var
 like : mass;
 photo : photoMass;
 n, i : longint;
 ans : longint;
begin
 readln(n);
 for i := 1 to n do
   read(like[i]);

 for i := 1 to maxPhoto do
   photo[i] := 0;

 ans := 1;
 for i := 1 to n do
  begin
   inc(photo[like[i]]);
   if photo[ans] < photo[like[i]]
      then ans := like[i];
  end;

 write(ans);
end.