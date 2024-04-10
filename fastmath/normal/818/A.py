n, k = map(int, input().split())

l = 0
r = 10 ** 12 + 1
while (l < r - 1):
    m = (l + r) // 2
    if m + m * k <= n // 2:
        l = m
    else:
        r = m
        
print(l, l * k, n - l * (k + 1))