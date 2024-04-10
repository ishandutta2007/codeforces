from __future__ import division

M, N = map(int, raw_input().split())

numer = 0
prev = 0
for i in xrange(1, M):
    numer += (i / M) ** N

numer = M - numer

print numer