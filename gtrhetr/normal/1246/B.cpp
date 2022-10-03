#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod1 998244353LL
#define mod2 1000000007LL
#define pll pair<ll,ll>

map<pll,int> mp;

ll bin1[100010],bin2[100010];
int p[100010],mn[100010],num[100010],n,k,sq,tot;
bool bo[100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void pre_gao()
{
	for (int i=2;i<=100000;i++)
	{
		if (!bo[i]) p[++tot]=i,mn[i]=tot;
		for (int j=1;j<=tot&&i*p[j]<=100000;j++)
		{
			bo[i*p[j]]=true;mn[i*p[j]]=j;
			if (i%p[j]==0) break;
		}
	}
}

int main()
{
	n=rd();k=rd();pre_gao();
	for (int i=1;i<=n;i++) num[i]=rd();
	bin1[0]=1;
	for (int i=1;i<=100000;i++) bin1[i]=bin1[i-1]*233%mod1;
	bin2[0]=1;
	for (int i=1;i<=100000;i++) bin2[i]=bin2[i-1]*313%mod2;
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		ll h1=0,h2=0,h3=0,h4=0;
		int hh=num[i];
		while (hh>1)
		{
			int now=mn[hh],tt=0;
			while (hh%p[now]==0) tt++,hh/=p[now];
			tt%=k;
			h1=(h1+bin1[now]*tt)%mod1;
			h2=(h2+bin2[now]*tt)%mod2;
			tt=(k-tt)%k;
			h3=(h3+bin1[now]*tt)%mod1;
			h4=(h4+bin2[now]*tt)%mod2;
		}
		ans+=mp[pll(h3,h4)];
		mp[pll(h1,h2)]++;
	}
	printf("%lld\n",ans);
	return 0;
}