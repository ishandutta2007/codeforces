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

T = int(cin())
res = []
while T:
    T -= 1
    n, m = int(cin()), int(cin())
    s = [cin().decode() for i in range(n)]
    dp = [[None for j in range(2**n)] for i in range(m+1)]
    dp[0][0] = ""
    for x in range(m):
        for j in range(2**n):
            if dp[x][j] is None:
                continue
            for k in "qwertyuiopasdfghjklzxcvbnm":
                nj = j
                for i in range(n):
                    if s[i][x] != k:
                        nj ^= 1 << i
                if nj & j == j and dp[x+1][nj] is None:
                    dp[x+1][nj] = dp[x][j] + k
    for j in range(2**n):
        if dp[m][j] is not None:
            res.append(dp[m][j])
            break
    else:
        res.append("-1")
os.write(1, "\n".join(res).encode())