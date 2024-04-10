from math import gcd

n, a, b, p, q = map(int, input().split())
g = n // (a * b // gcd(a, b))
print((n // a - g) * p + (n // b - g) * q + g * max(p, q))