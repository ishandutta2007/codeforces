//why on god's earth does Pascal have BigInt
//and it's faster than Java too
//what the f$ck

uses gmp;

var s: string;
    n, b, p: MPInteger;
    ans, l: longint;
    
begin
    readln(s);
    n := s;
    if s = '1' then begin
        writeln(1);
    end
    else begin
        b := 3;
        s := z_get_str(3, n);
        l := length(s);
        p := z_pow_ui(b, l-1);
        ans := l*3;
        if p+p >= n then ans := (l-1)*3+2;
        if p*4 >= n*3 then ans := (l-2)*3+4;
        if p >= n then ans := (l-1)*3;
        writeln(ans);
    end;
end.