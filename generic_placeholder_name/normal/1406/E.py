def main():
    n = int(input())
    
    isprime = [True] * (n+1)
    isprime[0], isprime[1] = False, False
    for i in range(1, int(n ** 0.5) + 1):
        if isprime[i]:
            for j in range(i ** 2, n + 1, i):
                isprime[j] = False
              
    rem = [True] * (n+1)
    factors = []
    
    s = n
    has_first = False
    buf_size = 95
    cyc = 0
    
    primes = []
    
    for i in range(1, n+1):
        if isprime[i]:
            primes.append(i)
    
    for i in range(len(primes)):
        p = primes[i]
        cur = 0
        for j in range(p, n+1, p):
            cur += rem[j]
            s -= rem[j]
            rem[j] = False
        print('B', p)
        res = int(input())
        if res != cur:
            factors.append(p)
        cyc += 1
        if cyc == buf_size and not has_first:
            cyc = 0
            print('A', 1)
            res = int(input())
            if res != s:
                for j in range(i - buf_size + 1, i+1):
                    print('A', primes[j])
                    res_j = int(input())
                    if res_j != 0:
                        has_first = True
                        factors.append(primes[j])
                        break
                assert(has_first)
                    
    if not has_first:
        for j in range(len(primes) - cyc, len(primes)):
            print('A', primes[j])
            res_j = int(input())
            if res_j != 0:
                has_first = True
                factors.append(primes[j])
                break
                
    ans = 1
    for x in factors:
        l, r, tmp = 1, 0, n
        while tmp >= x:
            tmp /= x
            r += 1
        while l < r:
            m = (l + r + 1) // 2
            print('A', x ** m)
            res = int(input())
            if res != 0:
                l = m
            else:
                r = m - 1
        ans *= x ** r
    
    print('C', ans)
    
main()