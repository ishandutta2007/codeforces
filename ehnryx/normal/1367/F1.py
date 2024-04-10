import os
### START FAST IO ###
inp = os.read(0, int(1e7)).split()
inp_pos = -1
def cin():
    global inp_pos
    inp_pos += 1
    return inp[inp_pos]
# cout: os.write(1, "\n".encode().join(res))
#### END FAST IO ####

from itertools import groupby
from bisect import bisect

T = int(cin())
res = []
while T:
    T -= 1
    n = int(cin())
    a = [
        [x[1] for x in g]
        for k, g in groupby(
            sorted([(int(cin()), i) for i in range(n)]),
            lambda x: x[0]
        )
    ]

    ans = 0
    left = 0
    cur = 0
    m = len(a)
    for right in range(m):
        if right > 0 and a[right][0] < a[right-1][-1]:
            left = right
            cur = 0
        cur += len(a[right])
        val = cur
        if left > 0:
            val += bisect(a[left-1], a[left][0])
        if right+1 < m:
            val += len(a[right+1]) - bisect(a[right+1], a[right][-1])
        ans = max(ans, val)
    res.append(str(n - ans).encode())

os.write(1, "\n".encode().join(res))