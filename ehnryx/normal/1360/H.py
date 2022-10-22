import os
### START FAST IO ###
os_input = os.read(0, int(1e7)).split()
os_input_pos = -1
def cin():
    global os_input_pos
    os_input_pos += 1
    return os_input[os_input_pos]
# cout: os.write(1, "\n".join(res).encode())
#### END FAST IO ####

from bisect import bisect

T = int(cin())
res = []
while T:
    T -= 1
    n, m = int(cin()), int(cin())
    ans = (2**m - 1) // 2
    a = sorted([int(cin(), 2) for i in range(n)])
    leq = bisect(a, ans)
    small = ans + 1 - leq
    big = 2**m - 1 - ans - (n - leq)

    have = set(a)
    while small > big:
        if ans not in have:
            small -= 1
            big += 1
        ans -= 1
    while small < big:
        ans += 1
        if ans not in have:
            small += 1
            big -= 1
    while ans in have:
        ans -= 1
    res.append(bin(ans)[2:].zfill(m))
os.write(1, "\n".join(res).encode())