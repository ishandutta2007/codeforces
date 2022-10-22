#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
LL n;
char op[505][2];
LL a[505],st[505],dp[505][505],ans;
int main(){
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i)
	{
		scanf("%s",op[i]);
		st[i]=(*op[i]=='+');
		if(st[i])	scanf("%lld",&a[i]);
	}
	for(LL i=1;i<=n;++i)
	{
		if(!st[i])	continue;
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		for(LL j=1;j<i;++j)
		{
			if(st[j])
			{
				if(a[j]>a[i])
				{
					for(LL k=0;k<=n;++k)	dp[j][k]=(dp[j-1][k]*2)%MOD;
				}
				else
				{
					for(LL k=0;k<=n;++k)	dp[j][k]=dp[j-1][k];
					for(LL k=0;k<n;++k)	(dp[j][k+1]+=dp[j-1][k])%=MOD;
				}
			}
			else
			{
				for(LL k=0;k<=n;++k)	dp[j][k]=dp[j-1][k];
				for(LL k=0;k<=n;++k)	(dp[j][k]+=dp[j-1][k+1])%=MOD;
				(dp[j][0]+=dp[j-1][0])%=MOD;
			}
		}
		for(LL k=0;k<=n;++k)	dp[i][k]=dp[i-1][k];
		for(LL j=i+1;j<=n;++j)
		{
			if(st[j])
			{
				if(a[j]>=a[i])
				{
					for(LL k=0;k<=n;++k)	dp[j][k]=(dp[j-1][k]*2)%MOD;
				}
				else
				{
					for(LL k=0;k<=n;++k)	dp[j][k]=dp[j-1][k];
					for(LL k=0;k<n;++k)	(dp[j][k+1]+=dp[j-1][k])%=MOD;
				}
			}
			else
			{
				for(LL k=0;k<=n;++k)	dp[j][k]=dp[j-1][k];
				for(LL k=0;k<=n;++k)	(dp[j][k]+=dp[j-1][k+1])%=MOD;
			}
		}
		LL sum=0;
		for(LL k=0;k<=n;++k)	(sum+=dp[n][k])%=MOD;
		(ans+=sum*a[i]%MOD)%=MOD;
//		printf("%lld %lld\n",sum,i);
//		for(LL j=0;j<=n;++j)
//		{
//			for(LL k=0;k<=n;++k)	printf("%lld ",dp[j][k]);
//			puts("");
//		}
	}
	printf("%lld",ans);
	return 0;
}