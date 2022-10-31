n, a, b, c = map(int,input().split())
ans = 20 * max( a , b , c )
dp = [ ans for i in range(20) ]
dp[ 0 ] = 0
for i in range(0, 20):
  if i+1<20: dp[i+1] = min( dp[i+1] , dp[i]+a )
  if i+2<20: dp[i+2] = min( dp[i+2] , dp[i]+b )
  if i+3<20: dp[i+3] = min( dp[i+3] , dp[i]+c )
for i in range(0, 20):
  if (n+i)%4 == 0:
    ans = min(ans,dp[i])
print(ans)