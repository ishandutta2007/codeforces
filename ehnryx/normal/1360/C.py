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

T = int(cin())
res = []
while T:
    T -= 1
    n = int(cin())
    a = sorted([int(cin()) for i in range(n)])
    even = [x % 2 for x in a].count(0)
    if even % 2 == 0:
        res.append("YES".encode())
    else:
        for i, v in enumerate(a):
            if i > 0 and a[i-1] == v - 1:
                res.append("YES".encode())
                break
        else:
            res.append("NO".encode())
os.write(1, "\n".encode().join(res))