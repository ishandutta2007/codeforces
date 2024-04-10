var
  a, b, c, d: extended;

begin
  readln(a, b, c);
  if a = 0
     then begin
            if b = 0
               then begin
                      if c = 0 then writeln(-1) else writeln(0);
                    end
               else begin
                      writeln(1);
                      writeln(-c / b : 0 : 10);
                    end; 
          end
     else begin
            d := b * b - 4 * a * c;
            if d < 0 then writeln(0);
            if d = 0 then begin writeln(1); writeln(-b / (2 * a) : 0 : 10); end;
            if d > 0 
               then begin
                      writeln(2);
                      if a > 0
                         then begin 
                                writeln((-b - sqrt(d)) / (2 * a) : 0 : 10); 
                                writeln((-b + sqrt(d)) / (2 * a) : 0 : 10);
                              end
                         else begin 
                                writeln((-b + sqrt(d)) / (2 * a) : 0 : 10); 
                                writeln((-b - sqrt(d)) / (2 * a) : 0 : 10);
                              end;     
                    end;   
          end; 
end.