x, t, a, b, da, db = [int(x) for x in raw_input().split()]
ok = False
for t1 in range(t):
    for t2 in range(t):
        for p1 in range(2):
            for p2 in range(2):
                if p1 * (a - da * t1) + p2 * (b - db * t2) == x:
                    ok = True
if ok:
    print 'YES'
else:
    print 'NO'