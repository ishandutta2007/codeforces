n = -int(raw_input())
a = [(n + 90 * i) % 360 for i in xrange(4)]
a = [min(x, 360 - x) for x in a]
res = 0
for i in xrange(1, 4):
    if a[i] < a[res]:
        res = i
print res