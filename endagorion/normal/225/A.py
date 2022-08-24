def readInt():
    return tuple([int(x) for x in raw_input().split()])

N, = readInt()
top, = readInt()
ok = True
for i in xrange(N):
    a, b = readInt()
    if top in [a, b] or 7 - top in [a, b]:
        ok = False
print "YES" if ok else "NO"