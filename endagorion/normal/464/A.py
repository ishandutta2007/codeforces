def check(s, i):
    return not (i > 0 and s[i] == s[i - 1]) and not (i > 1 and s[i] == s[i - 2])

n, p = map(int, raw_input().split())
s = raw_input()
a = [ord(s[i]) - ord('a') for i in xrange(n)]
i = n - 1
fw = 0
while i >= 0 and i < n:
    if fw:
        a[i] = -1
    a[i] += 1
    while not check(a, i) and a[i] < p:
        a[i] += 1
    if a[i] < p:
        fw = 1
    i += (1 if fw else -1)
if i == n:
    print ''.join([chr(a[i] + ord('a')) for i in xrange(n)])
else:
    print "NO"