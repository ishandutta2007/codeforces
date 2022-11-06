from math import sqrt
n, k = map(int, input().split())
max_d = 0
for d in range(1, int(sqrt(n) + 2)):
    if n % d != 0:
        continue
    if d * k * (k + 1) // 2 <= n:
        max_d = max(max_d, d)
    if n // d * k * (k + 1) // 2 <= n:
        max_d = max(max_d, n // d)
if max_d == 0:
    print(-1)
    exit(0)
for i in range(k - 1):
    print((i + 1) * max_d, end=' ')
    n -= (i + 1) * max_d
print(n)