var
  n,i:longint;
begin
  readln(n);
  write('+');
  for i:=1 to 24 do write('-');
  writeln('+');
  write('|');
  if n>=1 then write('O') else write('#');
  write('.');
  for i:=1 to 10 do
    if n>=3*i+2 then write('O.') else write('#.');
  writeln('|D|)');
  write('|');
  if n>=2 then write('O') else write('#');
  write('.');
  for i:=1 to 10 do
    if n>=3*i+3 then write('O.') else write('#.');
  writeln('|.|');
  write('|');
  if n>=3 then write('O') else write('#');
  write('.');
  for i:=1 to 22 do write('.');
  writeln('|');
  write('|');
  if n>=4 then write('O') else write('#');
  write('.');
  for i:=1 to 10 do
    if n>=3*i+4 then write('O.') else write('#.');
  writeln('|.|)');
  write('+');
  for i:=1 to 24 do write('-');
  writeln('+');
end.