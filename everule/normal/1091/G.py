from random import randint
from sys import stdout
from math import gcd
rq = 0
def miller_rabin(n, k):

    if n == 2:
        return True

    if n % 2 == 0:
        return False

    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = randint(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True
def getsqrt(x, n):
    for i in range(1, 10 * n):
        if((i * i) % n == x and randint(1, 2) == 1):
            return i % n
    return -1
def solve(n, q):
    if(q == 0):
        return set({n})
    x = randint(1, n-1)
    s = x * x % n
    print("sqrt " + str(s))
    stdout.flush()
    y = int(input())
    #y = getsqrt(s, n)
    #print(x, y, s)
    primes = solve(n, q-1)
    nprimes = set()
    for p in primes:
        ng = gcd(p, x+y)
        if(ng != 1 and ng != p):
            nprimes.add(p // ng)
            nprimes.add(ng)
        else:
            nprimes.add(p)
    for p in primes:
        ng = gcd(p, abs(x-y))
        if(ng != 1 and ng != p):
            nprimes.add(p // ng)
            nprimes.add(ng)
        else:
            nprimes.add(p)
    return nprimes
n = int(input())
rq = 0
ans = solve(n, 13)
print("! " + str(len(ans)) + " ", end="")

for x in ans:
    print(str(x) + " ", end="")
stdout.flush()