n, m, k = map(int, input().split())

mod = int(1e9 + 7)

def pow(a, n):
    res = 1
    while n:
        if n & 1:
            res = res * a % mod
        n //= 2
        a = a * a % mod
    return res

if k == -1 and (n + m) % 2 == 1:
    print(0)
else:
    print(pow(2, (n - 1) * (m - 1)))