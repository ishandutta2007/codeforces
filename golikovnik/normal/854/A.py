def gcd(x, y):
    while y:
        x %= y
        x, y = y, x
    return x
n = int(input())
mx_a = 1
mx_b = n - 1
for i in range(2, n // 2 + 1):
    a = i
    b = n - a
    if b <= a:
        continue
    g = gcd(a, b)
    if g != 1:
        continue
    if a * mx_b > b * mx_a:
        mx_a, mx_b = a, b
print(mx_a, mx_b)