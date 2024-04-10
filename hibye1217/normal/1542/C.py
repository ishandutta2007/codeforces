def gcd(a, b):
    if b == 0: return a
    return gcd(b, a%b);

def lcm(a, b):
    return a*b // gcd(a, b);

mod = 1000000007

t = int( input() )
for _ in range(t):
    n = int( input() )
    l, i = 1, 1
    ans = 0
    while n > 0:
        i += 1
        pl = lcm(l, i)
        r = pl // l
        res = ( (r-1)*n + r-1 ) // r
        ans += res*i; ans %= mod
        n -= res; l = pl
    print(ans)