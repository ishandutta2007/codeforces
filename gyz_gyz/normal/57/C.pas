const mx:int64=1000000007;
var
  a:array[0..2000000]of int64;
  i:longint;
  n,ans:int64;
function f(x:int64):int64;
var a,b:int64;
begin
  if x=1 then exit(1) else begin
    a:=mx div x+1;b:=a*x-mx;
    exit(f(b)*a mod mx);
  end;
end;
begin
  readln(n);a[0]:=1;
  for i:=1 to n*2 do a[i]:=a[i-1]*i mod mx;
  ans:=a[n*2-1]*f(a[n]) mod mx*f(a[n-1]) mod mx;
  writeln((ans*2-n+mx) mod mx);
end.