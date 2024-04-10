n = int(raw_input())
print (n // 2) * (n - n // 2)
for i in xrange(0, n // 2):
    for j in xrange(n // 2, n):
        print i + 1, j + 1