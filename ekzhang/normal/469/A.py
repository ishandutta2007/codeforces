def discardAll(s, li):
    for i in li:
        s.discard(i)

N = input()
s = set(xrange(1, N + 1))
discardAll(s, (int(x) for x in raw_input().split()[1:]))
discardAll(s, (int(x) for x in raw_input().split()[1:]))
if s:
    print 'Oh, my keyboard!'
else:
    print 'I become the guy.'