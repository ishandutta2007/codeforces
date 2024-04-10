program hui;

{$APPTYPE CONSOLE}

var
 x: integer;
 a: array[1..40] of string;
 
begin
 read(x);
 a[1] := 'Washington';
 a[2] := 'Adams';
 a[3] := 'Jefferson';
 a[4] := 'Madison';
 a[5] := 'Monroe';
 a[6] := 'Adams';
 a[7] := 'Jackson';
 a[8] := 'Van Buren';
 a[9] := 'Harrison';
 a[10] := 'Tyler'; 
 a[11] := 'Polk';
 a[12] := 'Taylor';
 a[13] := 'Fillmore';
 a[14] := 'Pierce';
 a[15] := 'Buchanan';
 a[16] := 'Lincoln';
 a[17] := 'Johnson';
 a[18] := 'Grant';
 a[19] := 'Hayes';
 a[20] := 'Garfield';
 a[21] := 'Arthur'; 
 a[22] := 'Cleveland';
 a[23] := 'Harrison';
 a[24] := 'Cleveland';
 a[25] := 'McKinley';
 a[26] := 'Roosevelt';
 a[27] := 'Taft';
 a[28] := 'Wilson';
 a[29] := 'Harding';
 a[30] := 'Coolidge';
 a[31] := 'Hoover'; 
 a[32] := 'Roosevelt';
 a[33] := 'Truman';
 a[34] := 'Eisenhower';
 a[35] := 'Kennedy';
 a[36] := 'Johnson';
 a[37] := 'Nixon';
 a[38] := 'Ford';
 a[39] := 'Carter';
 a[40] := 'Reagan';
 writeln(a[x]);
end.