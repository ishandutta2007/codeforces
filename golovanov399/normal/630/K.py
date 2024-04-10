n = int(raw_input())
a = []
for i in xrange(2520):
    ok = False
    for j in xrange(2, 11):
        if i % j == 0:
            ok = True
    a.append(0 if ok else 1)

s = [0]
for i in xrange(2520):
    s.append(s[-1] + a[(i + 1) % 2520])

print n // 2520 * s[2520] + s[n % 2520]