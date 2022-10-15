const
 maxN = 150000 + 500;
 maxK = 100;

type
 mass = array [1 .. maxN] of longint;
 window = array [0 .. maxK] of longint;
var
 a, typ, id : mass;
 w : window;
 n, k, q : longint;
 i : longint;

 procedure add(num : longint);
  var
   i : longint;
   min : longint;
  begin
   if w[0] < k
      then begin
           inc(w[0]);
           w[w[0]] := num;
           end
      else begin
           min := 1;
           for i := 1 to w[0] do
           if a[w[min]] > a[w[i]]
              then min := i;
           if a[w[min]] < a[num]
              then w[min] := num;
           end;
  end;

 procedure writing(num : longint);
  var
   i : longint;
  begin
   for i := 1 to w[0] do
     if num = w[i]
        then begin
             writeln('YES');
             exit;
             end;
   writeln('NO');
  end;

begin
 readln(n, k, q);
 for i := 1 to n do
   read(a[i]);
 readln;
 for i := 1 to q do
   readln(typ[i], id[i]);

 w[0] := 0;
 for i := 1 to q do
   if typ[i] = 1
      then add(id[i])
      else writing(id[i]);
end.