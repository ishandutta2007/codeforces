import os
### START FAST IO ###
os_input = os.read(0, int(1e7)).split()
os_input_pos = -1
def cin():
    global os_input_pos
    os_input_pos += 1
    return os_input[os_input_pos]
# cout: os.write(1, "\n".encode().join(res))
#### END FAST IO ####

from math import gcd

T = int(cin())
res = []
while T:
    T -= 1
    n, m, a, b = [int(cin()) for i in range(4)]
    if n*a != m*b:
        res.append("NO")
        continue

    res.append("YES")
    g = [['0' for j in range(m)] for i in range(n)]
    ma = gcd(m, a)
    nb = gcd(n, b)
    a //= ma
    b //= nb
    m //= ma
    n //= nb
    for i in range(nb):
        for j in range(ma):
            for ii in range(n):
                for jj in range(a):
                    g[i*n + ii][j*m + (ii + jj) % m] = '1'
    res.append("\n".join([''.join(row) for row in g]))

os.write(1, "\n".join(res).encode())