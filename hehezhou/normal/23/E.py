maxn = 710
to = [[] for i in range(maxn)]
dp = [[0 for i in range(maxn)] for i in range(maxn)]
size = [0 for i in range(maxn)]
n = int(input())
def dfs(now, f):
    size[now] = 1
    dp[now][1] = 1
    for i in to[now]:
        if i != f:
            dfs(i, now)
            size[now] += size[i]
            for j in reversed(range(0, size[now] + 1)):
                for k in range(max(0, j - size[now] + size[i]), min(j, size[i]) + 1):
                    dp[now][j] = max(dp[now][j], dp[now][j - k] * dp[i][k])
    for i in range(1, n + 1):
        dp[now][0] = max(dp[now][0], dp[now][i] * i)

for i in range(1, n):
    u, v = map(int, input().split(' '))
    to[u].append(v)
    to[v].append(u)

dfs(1, 0)
print(dp[1][0])