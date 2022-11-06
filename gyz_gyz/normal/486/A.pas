var x:int64;
begin
  readln(x);
  if x and 1=1 then write('-');
  writeln((x+1) shr 1);
end.