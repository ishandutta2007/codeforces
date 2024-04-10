from itertools import permutations

n, k = map(int, raw_input().split())
d = {}

l = map(int, raw_input().split())
d[tuple(l)] = 1.0

def populate(f, y, pr):
    for i in xrange(len(y)):
        for j in xrange(i, len(y)):
            mid = y[j:i-1:-1] if i != 0 else y[j::-1]
            th = tuple(y[:i] + mid + y[j+1:])
            
            #print i, j, th
            f[th] = f.get(th, 0) +  pr * 2.0 / (len(y) * (len(y)+1)) 


def ct(y):
    ans = 0
    for i in xrange(len(y)):
        for j in xrange(i+1, len(y)):
            if y[j] < y[i]: ans += 1
    return ans

for it in xrange(k):
    f = {}
    for y in d:
        populate(f, y, d[y])
    d = f

ans = 0

for y in d:
    #print y, d[y], ct(y)
    ans += d[y] * ct(y)

print "%.15f" % ans