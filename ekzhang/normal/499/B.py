n, m = map(int, raw_input().split())

words = {}
for _ in xrange(m):
    a, b = raw_input().split()
    words[a] = b

d = raw_input().split()
res = []
for i in d:
    if len(words[i]) < len(i):
        res.append(words[i])
    else:
        res.append(i)

print ' '.join(res)