program palindrome;

const
  MAX = 5000000;

var
  i, j, ans: longint; c1, c2, p, q: int64;
  wp: array [1 .. MAX] of boolean;

function pln(v: longint): boolean;
var s: string;
    i: longint;
begin
  str(v, s);
  for i := 1 to length(s) do
    if s[i] <> s[length(s) - i + 1] then exit(false);
  exit(true);
end;

begin
  readln(p, q);
  c1 := 0; c2 := 0;
  for i := 1 to MAX do wp[i] := true;
  wp[1] := false;
  for i := 1 to MAX do
  begin
    if pln(i) then inc(c1);
    if wp[i]
       then begin
              inc(c2);
              j := i + i;
              while j <= MAX do
              begin
                wp[j] := false;
                inc(j, i);
              end;
            end;
    if c2 * q <= c1 * p then ans := i;
  end;
  writeln(ans);

end.