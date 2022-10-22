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
    n, k = int(cin()), int(cin())
    ans = n
    i = 1
    while i <= k and i*i <= n:
        if n % i == 0:
            ans = min(ans, n//i)
            if n//i <= k:
                ans = min(ans, i)
        i += 1
    res.append(str(ans).encode())
os.write(1, "\n".encode().join(res))