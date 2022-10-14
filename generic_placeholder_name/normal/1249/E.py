import sys
input = sys.stdin.readline

n, c = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
dp = [[0, 1e9] for _ in range(n)]
ans = [0] * n

for i in range(1, n):
    dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i-1]
    dp[i][1] = min(dp[i-1][0] + c, dp[i-1][1]) + b[i-1]
    ans[i] = min(dp[i][0], dp[i][1])
    
print(*ans)