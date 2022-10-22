#include <bits/stdc++.h>
#define constant const constexpr
typedef long long ll;
ll mod = 998244353;
ll dp[5003][5003];
ll f(int i,int j)
{
	if (i > j) std::swap(i,j);
	return dp[i][j];
}
int main()
{
	for (int i=0;i<=5000;++i) dp[0][i] = 1LL;
	for (int i=1;i<=5000;++i) dp[1][i] = 1LL+i;
	for (int i=2;i<=5000;++i)
	for (int j=i;j<=5000;++j)
	{
		dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*j)%mod;
	}
	int a,b,c;
	std::scanf("%d %d %d",&a,&b,&c);
	ll ans = 1;
	ans = (ans*f(a,b))%mod;
	ans = (ans*f(b,c))%mod;
	ans = (ans*f(a,c))%mod;
	std::printf("%I64d",ans);
}