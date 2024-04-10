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
    ans = 0x3f3f3f3f
    for i, v in enumerate(a):
        if i > 0:
            ans = min(ans, v - a[i-1])
    res.append(str(ans).encode())
os.write(1, "\n".encode().join(res))