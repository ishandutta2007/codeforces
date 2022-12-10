import sys
sys.setrecursionlimit(9999)

a = sys.stdin.readlines()[1:]
n = len(a)
m = len(a[0])
vis = [[0 for i in range(m)] for j in range(n)]
found = False

def dfs(x, y, fx, fy):
    global found, vis, a
    if vis[x][y] == 1:
        return
    if vis[x][y] < 0:
        found = True
        return
    dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    vis[x][y] = -1
    for (dx, dy) in dirs:
        x0, y0 = x + dx, y + dy
        if x0 < 0 or x0 >= n or y0 < 0 or y0 >= m:
            continue
        if x0 == fx and y0 == fy:
            continue
        if a[x][y] != a[x0][y0]:
            continue
        dfs(x0, y0, x, y)
    vis[x][y] = 1

for i in range(n):
    for j in range(m):
        if vis[i][j] == 0:
            dfs(i, j, -1, -1)
print ("Yes" if found else "No")