program Project710A;
var input: ansistring;
begin
read(input);
if ((input[1] = 'a') or (input[1] = 'h')) and ((input[2] = '1') or (input[2] = '8')) then write(3)
else if ((input[1] = 'a') or (input[1] = 'h')) xor ((input[2] = '1') or (input[2] = '8')) then write(5)
else write(8);
end.