#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,mod,dp1[4000005],dp2[4000005],sum[4000005];
#define MOD mod
int main(){
	scanf("%lld %lld",&n,&mod);
	dp1[1]=dp2[1]=1;
	for(LL i=1;i<=n;i++)
	{
		(dp1[i]+=(sum[i]+dp2[i-1]))%=mod;
		dp2[i]=(dp2[i-1]+dp1[i])%mod;
		(sum[i+1]+=sum[i])%=mod;
		for(LL j=2;j*i<=n;++j)	(sum[j*i]+=dp1[i])%=mod,(sum[min(j*i+j,n+1)]+=mod-dp1[i])%=mod;
	}
	printf("%lld",dp1[n]);
	return 0;
}