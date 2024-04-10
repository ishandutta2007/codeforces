n, b = map(int, input().split())

b2 = b
factors = []
for i in range(2, b2):
    if i * i > b2:
        break
    c = 0
    while b2 % i == 0:
        c += 1
        b2 //= i
    if c > 0:
        factors.append((i, c))
if b2 > 1:
    factors.append((b2, 1))

zero_count = n**3
for f, div in factors:
    count = 0
    f2 = f
    while f2 <= n:
        count += n // f2
        f2 *= f
    zero_count = min(zero_count, count // div)

print(zero_count)