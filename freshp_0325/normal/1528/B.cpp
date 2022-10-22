#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
LL dp[1000005],sgm[1000005];
LL cnt,prime[200005];
bool vis[1000005];
LL QuickPow(LL x,LL p)
{
	LL ans=1,base=x;
	while(p)
	{
		if(p&1)	(ans*=base)%=MOD;
		(base*=base)%=MOD;
		p>>=1;
	}
	return ans;
}
void shai(LL up)
{
	dp[1]=1;
	for(LL i=2;i<=up;++i)
	{
		if(!vis[i])	prime[++cnt]=i,dp[i]=sgm[i]=2;
		for(LL j=1;j<=cnt && prime[j]*i<=up;++j)
		{
			vis[prime[j]*i]=true;
			if(i%prime[j])
			{
				(dp[i*prime[j]]=dp[i]*2)%=MOD;
				sgm[i*prime[j]]=2;
				continue;
			}
			dp[prime[j]*i]=dp[i]*(sgm[i]+1)%MOD*QuickPow(sgm[i],MOD-2)%MOD;
			sgm[prime[j]*i]=sgm[i]+1;
			break;
		}
	}
}
//LL sum[1000005];
int n;
int main(){
	scanf("%d",&n);
	shai(n);
	LL ans=0,sum=0;
	for(int i=1;i<=n;++i)
	{
		ans=(sum+dp[i])%MOD;
		(sum+=ans)%=MOD; 
	}
	printf("%lld",ans);
	return 0;
}