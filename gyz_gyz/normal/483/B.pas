var a,b,c,p,q,l,r,m,x,y,z:int64;
function gcd(x,y:int64):int64;
begin
  if y=0 then exit(x) else exit(gcd(y,x mod y));
end;
begin
  readln(p,q,a,b);
  c:=a div gcd(a,b)*b;
  l:=0;r:=2000000000000000000;m:=(l+r) shr 1;
  while l<r do begin
    z:=m-m div a-m div b+m div c;
    x:=m-m div a-z;y:=m-m div b-z;
    if (x+z<p)or(y+z<q)or(x+y+z<p+q) then l:=m+1 else r:=m;
    m:=(l+r) shr 1;
  end;
  writeln(m);
end.