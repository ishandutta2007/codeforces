from itertools import accumulate
n = int(input())
q = list(map(int, input().split(' ')))
qs = [0] + list(accumulate(q))
qmin = min(qs)
p = [i - qmin for i in qs]
if all(i == v for i, v in enumerate(sorted(p))):
    print(' '.join(str(i + 1) for i in p))
else:
    print(-1)