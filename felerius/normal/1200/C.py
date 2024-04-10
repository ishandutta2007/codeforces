from math import gcd
n, m, q = map(int, input().split())
g = gcd(n, m)
ng = n // g
mg = m // g
for _ in range(q):
    sx, sy, ex, ey = map(int, input().split())
    sy -= 1
    ey -= 1
    sec1 = sy // ng if sx == 1 else sy // mg
    sec2 = ey // ng if ex == 1 else ey // mg
    print('YES' if sec1 == sec2 else 'NO')