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
    g = [cin().decode() for i in range(n)]
    for i in range(n-1):
        for j in range(n-1):
            if g[i][j] == '1' and g[i+1][j] == '0' and g[i][j+1] == '0':
                res.append("NO".encode())
                break
        else:
            continue
        break
    else:
        res.append("YES".encode())
os.write(1, "\n".encode().join(res))