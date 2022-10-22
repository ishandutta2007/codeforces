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
    k = int(cin())
    s = "0"*k + cin().decode() + "0"*k + "1"
    ans = 0
    cur = 0
    for c in s:
        if c == "1":
            ans += (cur + 1) // (k + 1) - 1
            cur = 0
        else:
             cur += 1
    res.append(str(ans).encode())
os.write(1, "\n".encode().join(res))