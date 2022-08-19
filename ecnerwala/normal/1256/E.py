n=int(input())
a=sorted((int(v),i) for i,v in enumerate(input().split()))
INF=10**18
dp=[-INF,-INF,0]
for i in range(n-1):
    dp.append(max(dp[-1],dp[i]+a[i+1][0]-a[i][0]))
cur,t = n-1,1
o=[0]*n
while cur >= 0:
    if dp[cur] == dp[cur-1]:
        o[a[cur][1]] = t
        cur -= 1
    else:
        o[a[cur][1]] = o[a[cur-1][1]] = o[a[cur-2][1]] = t
        cur -= 3
        t += 1
print(a[-1][0] - a[0][0] - dp[n-1], t-1)
print(*o)