s = (0, 0, 0)
for i in xrange(input()):
    s = map(lambda x: x[0] + x[1], zip(s, map(int, raw_input().split())))
print any(s) and "NO" or "YES"