from __future__ import division

home = map(int, raw_input().split())
univ = map(int, raw_input().split())
n = input()
roads = [map(int, raw_input().split()) for _ in xrange(n)]

def isacross(a, b, c):
    home_val = a * home[0] + b * home[1] + c
    univ_val = a * univ[0] + b * univ[1] + c
    return ((home_val < 0 and univ_val > 0) or
            (home_val > 0 and univ_val < 0))

ans = 0
for i in roads:
    if isacross(*i):
        ans += 1
print ans