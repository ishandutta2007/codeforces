#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
int n,a[301],ans,sum,cnt,fac[401],inv[401],cur,f[2][401];
map<int,int> mp;
const int mod=1000000007;
inline int pw(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
inline int c(int x,int y)
{
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
	//freopen("permutation.in","r",stdin);
	//freopen("permutation.out","w",stdout);
	scanf("%lld",&n);
	fac[0]=inv[0]=1;
	for(register int i=1;i<=400;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=pw(fac[i],mod-2);
	}
	for(register int i=1;i<=n;++i)
	{
		int x,val=1;
		scanf("%lld",&x);
		for(register int j=2;j*j<=x;++j)
		{
			bool flag=0;
			while(x%j==0)
			{
				flag^=1;
				x/=j;
			}
			if(flag)
				val*=j;
		}
		if(x)
			val*=x;
		if(!mp[val])
			mp[val]=++cnt;
		++a[mp[val]];
	}
	f[cur][0]=1;
	for(register int i=1;i<=cnt;++i)
	{
		cur^=1;
		for(register int t=0;t<=a[i]+sum+1;++t)
			f[cur][t]=0;
		for(register int k=1;k<=a[i]&&k<=sum+1;++k)
			for(register int j=0;j<=sum;++j)
				for(register int l=0;l<=k&&l<=j;++l)
				f[cur][j-l+a[i]-k]=(f[cur][j-l+a[i]-k]+f[cur^1][j]*c(a[i]-1,k-1)%mod*c(j,l)%mod*c(sum+1-j,k-l)%mod)%mod;
		sum+=a[i];
	}
	ans=f[cur][0];
	for(register int i=1;i<=cnt;++i)
		ans=ans*fac[a[i]]%mod;
	printf("%lld\n",ans);
	return 0;
}