const
  to20: array [0 .. 19] of string = 
    ('zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight',
     'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen',
     'sixteen', 'seventeen', 'eighteen', 'nineteen'); 
  more: array [2 .. 9] of string = 
    ('twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety');


var
  i: longint;
  
 begin
   readln(i);
   if i < 20 then write(to20[i]) 
      else begin
             write(more[i div 10]);
             if i mod 10 <> 0 then write('-', to20[i mod 10]); 
           end;
 end.