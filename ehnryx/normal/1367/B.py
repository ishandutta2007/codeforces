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

T = int(cin())
res = []
while T:
    T -= 1
    n = int(cin())
    bad = [0, 0]
    for i in range(n):
        a = int(cin())
        if a%2 != i%2:
            bad[i%2] += 1
    res.append(str(bad[0] if bad[0] == bad[1] else -1).encode())
os.write(1, "\n".encode().join(res))