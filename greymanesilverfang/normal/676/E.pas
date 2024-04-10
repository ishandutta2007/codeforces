const nmax = 100001;

var n,k,i,cnt: longint;
    str, str1 : string;
    A: array[1..nmax] of longint;

procedure CheckDivisible;
var lol, sum: int64;
begin;
     sum := 0;
     lol := 1;
     for i := 1 to n do
     begin
          sum := (sum + a[i]*lol) mod 32416187567;
          lol := lol*k mod 32416187567;
     end;
     if sum = 0 then write('Yes') else write('No');
end;

begin
     cnt := 0;
     readln(n,k);
     inc(n);
     readln(str1);
     if str1 = '?' then inc(cnt) else val(str1,A[1]);
     for i := 2 to n do
     begin
          readln(str);
          if str = '?' then inc(cnt) else val(str,A[i]);
     end;
     if cnt = 0 then CheckDivisible
     else
     begin
          if k=0 then
          begin
               if (str1 = '?') then if (n mod 2 <> cnt mod 2) then write('Yes') else write('No')
               else if A[1] = 0 then write('Yes') else write('No');
          end
          else if n mod 2 = 0 then write('Yes') else write('No');
     end;
end.