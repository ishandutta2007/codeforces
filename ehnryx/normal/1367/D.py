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
    s = sorted(list(cin().decode()))
    n = int(cin())
    a = [int(cin()) for i in range(n)]
    while a.count(0) and s:
        while s and s.count(s[-1]) < a.count(0):
            cur = s[-1]
            while s and s[-1] == cur:
                s.pop()
        if s:
            cur = s[-1]
            a = [cur if x == 0 else x for x in a]
            while s and s[-1] == cur:
                s.pop()
            for j in range(n):
                if not str(a[j]).isalpha():
                    for i in range(n):
                        if a[i] == cur:
                            a[j] -= abs(i - j)
    res.append(''.join(a).encode())
os.write(1, "\n".encode().join(res))