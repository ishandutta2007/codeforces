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
from math import gcd

T = int(cin())
res = []
while T:
    T -= 1
    n = int(cin())
    k = int(cin())
    a = [len(list(g)) for k, g in groupby(sorted(cin()))]
    ans = 0
    for v in range(1, n+1):
        d = gcd(v, k)
        f = v//d
        if sum([x//f for x in a]) >= d:
            ans = v
    res.append(str(ans).encode())
os.write(1, "\n".encode().join(res))