n, k = map(int, input().split())
a = n // 2 // (k + 1)
print(a, a * k, n - a * (k + 1))