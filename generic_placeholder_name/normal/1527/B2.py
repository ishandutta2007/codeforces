for s in[*open(0)][2::2]:
    s=s.strip();n=len(s);z=s.count('0');x=n&1&(s[n//2]=='0')
    if s==s[::-1]:print('BAOLBI C E'[(z>1)&x::2])
    else:print('ADLRIACWE'[(z==2)&x::2])