const solve_time: array[0..10] of integer =
      (0,5,15,30,50,75,105,140,180,225,275);
var n,k,i:integer;
begin
    read(n,k);
    for i:=n downto 0 do if solve_time[i]+k<=240 then break;
    write(i);
end.