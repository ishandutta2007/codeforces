import collections
import math
input()
a = map(int, input().split())
b = map(int, input().split())
counts = collections.defaultdict(int)
arbitrary = 0
for ai, bi in zip(a, b):
    if ai == 0:
        if bi == 0:
            arbitrary += 1
    else:
        if bi == 0:
            counts[(0, 0)] += 1
        else:
            if (ai < 0 and bi < 0) or (ai >= 0 and bi < 0):
                ai = -ai
                bi = -bi

            g = math.gcd(-bi, ai)
            counts[(-bi // g, ai // g)] += 1

if counts:
    print(max(counts.values()) + arbitrary)
else:
    print(arbitrary)