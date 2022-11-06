var a,b,c:int64;
begin
  readln(a,b,c);
  if (b+c)*2<a then a:=(b+c)*2;
  if (a+c)*2<b then b:=(a+c)*2;
  if (a+b)*2<c then c:=(a+b)*2;
  writeln((a+b+c) div 3);
end.