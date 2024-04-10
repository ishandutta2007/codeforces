def prime(n):
    d = 2
    res = []
    while d * d <= n:
        if n % d:
            d += 1
        else:
            res.append(d)
            n //= d
        
    res.append(n)
    return res



n, k = map(int, input().split())
p = prime(n)
if len(p) < k:
    print(-1)
else:
    for i in range(k - 1):
        print(p[i], end = ' ')
    
    l = 1
    for i in range(k - 1, len(p)):
        l *= p[i]
        
    print(l)