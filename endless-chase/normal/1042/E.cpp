#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=998244353;
long long dp[1111111],x,y,dx,dy;
long long sum[1111111],suma[1111111],sumb[1111111],sum2[1111111],n,m,a[1111][1111],pre,inv,cnt;
pair<long long,pair<long long,long long> > pa[1111111];
long long binpow(long long a,long long t)
{
	long long res=1,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p%mod;
		p=p*p%mod;
	}
	return res;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		for (long long j=1;j<=m;j++)
		{
			scanf("%I64d",&a[i][j]);
			pa[++cnt]=make_pair(a[i][j],make_pair(i,j));
		}
	}
	scanf("%I64d%I64d",&dx,&dy);
	sort(pa+1,pa+cnt+1);
	for (long long i=1;i<=cnt;i++)
	{
		if (i==1 || pa[i].first>pa[i-1].first)
		{
			pre=i-1;
			inv=binpow(pre,mod-2);
		}
		x=pa[i].second.first;y=pa[i].second.second;
		dp[i]=(sum[pre]+(pre*((x*x+y*y)%mod)%mod)+sum2[pre]-(2*x*suma[pre]%mod)-(2*y*sumb[pre]%mod))%mod;
		dp[i]=dp[i]*inv%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
		sum2[i]=(sum2[i-1]+x*x+y*y)%mod;
		suma[i]=(suma[i-1]+x)%mod;
		sumb[i]=(sumb[i-1]+y)%mod;
	}
	for (long long i=1;i<=cnt;i++)
	{
		if (pa[i].second.first==dx && pa[i].second.second==dy) 
		{
			printf("%I64d\n",(dp[i]+mod)%mod);
			return 0;
		}
	}
	return 0;
}