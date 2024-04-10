n, k = map(int, raw_input().split())

cur = 0
print n ** 3 - n * (n - k + 1) * (n + 1) // 2 + n
for i in xrange(n):
    for j in xrange(k - 1):
        cur += 1
        print cur,
    for j in xrange(n - k + 1):
        print n * n - (n - k + 1) * (i + 1) + j + 1,
    print