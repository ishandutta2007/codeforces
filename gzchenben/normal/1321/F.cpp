#include<cstdio>
#define base 3
#define mod 998244353
using namespace std;
int n,m,s[200005],sum[200005],a[200005],cnt;
long long hash[2][200005],fac[200005],inv;
long long qpow(long long x,long long y)
{
//	printf("qpow: x=%d y=%d",x,y);
	long long ans=1;
	while(y)
	{
		if(y%2) ans=ans*x%mod; 
		x=x*x%mod;
		y=y/2;
	}
//	printf(" ans=%d\n",ans);
	return ans;
}
void init()
{
	fac[0]=1;
	long long now=1;
	inv=qpow(base,mod-2);
	for(int i=1;i<=cnt;i++)
	{
		fac[i]=fac[i-1]*inv%mod;
		hash[0][i]=(hash[0][i-1]+(a[i]+1)*now)%mod;
		hash[1][i]=(hash[1][i-1]+(2-a[i])*now)%mod;
		now=now*base%mod;
	}
}
long long get(int flag,int l,int r)
{
	int ans=(hash[flag][r]-hash[flag][l-1]+mod)*fac[l-1]%mod;
//	printf("hash: flag=%d l=%d r=%d ans=%d\n",flag,l,r,ans);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char tmp;
		scanf(" %c",&tmp);
		s[i]=tmp-'0';
		if(s[i]==0) 
		{
			a[++cnt]=i%2;
		}
		sum[i]=sum[i-1]+(1-s[i]);
	}
	init();
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x1,x2,len;
		scanf("%d%d%d",&x1,&x2,&len);
		if(get(x1%2,sum[x1-1]+1,sum[x1+len-1])!=get(x2%2,sum[x2-1]+1,sum[x2+len-1]))
			printf("No\n");
		else 
			printf("Yes\n");
	}
}