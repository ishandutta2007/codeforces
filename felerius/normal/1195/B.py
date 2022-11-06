n, k = map(int, input().split())
c = 1
while c * (c + 1) // 2 < k:
    c += 1
while c * (c + 1) // 2 - (n - c) != k:
    c += 1
print(n - c)