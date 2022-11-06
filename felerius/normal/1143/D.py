import math
n, k = map(int, input().split())
a, b = map(int, input().split())
x = 10**20
y = 0

for s in (a, k - a):
    for i in range(n):
        for l in ((i * k - b - s + n*k) % (n*k), (i * k + b - s + n*k) % (n*k)):
            if l == 0:
                x = 1
                y = max(y, 1)
                continue
            gcd = math.gcd(n*k, l)
            lcm = n*k*l // gcd
            x = min(x, lcm // l)
            y = max(y, lcm // l)
print(x, y)