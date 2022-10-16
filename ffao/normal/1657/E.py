n,k=map(int,input().split())

dp = [[0 for x in range(k+1)] for y in range(n+1)]
dp[0] = [1]*(k+1)

mod=998244353

fac=[0]*(n+1)
fac[0]=1
for i in range(1,n+1): fac[i]=(fac[i-1]*i)%mod
inv = [pow(fac[i],mod-2,mod) for i in range(n+1)]

def C(n,k):
 return (fac[n]*inv[k]*inv[n-k])%mod

for used in range(1,n+1):
 for val in range(1,k+1):
  dp[used][val] = dp[used][val-1]
  for hm in range(1,used+1):
   dp[used][val] += dp[used-hm][val-1] * pow(k-val+1,(used-hm)*hm + hm*(hm-1)//2,mod) * C(n-1-used+hm,hm)
  dp[used][val] %= mod

print(dp[n-1][k])