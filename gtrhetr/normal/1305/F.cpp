#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<ll,bool> mp;

ll num[200010],ans;
int p[1000010],n,tot;
bool bo[1000010];

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void pre_gao()
{
	for (int i=2;i<=1000000;i++)
	{
		if (!bo[i]) p[++tot]=i;
		for (int j=1;j<=tot&&i*p[j]<=1000000;j++)
		{
			bo[i*p[j]]=true;
			if (i%p[j]==0) break;
		}
	}
}

mt19937 rnd(time(NULL));

inline void gao1(ll x)
{
	mp[x]=true;
	ll res=0;
	for (int i=1;i<=n;i++)
	{
		if (num[i]<=x) res+=x-num[i];
		else
		{
			ll hh=num[i]%x;
			res+=min(hh,x-hh);
		}
	}
	ans=min(ans,res);
}

inline void gao(ll x)
{
	static ll c[110];
	if (!x) return;
	int tt=0;
	for (int j=1;j<=tot;j++) if (x%p[j]==0)
	{
		c[++tt]=p[j];
		while (x%p[j]==0) x/=p[j];
	}
	if (x>1) c[++tt]=x;
	for (int i=1;i<=tt;i++) if (!mp[c[i]]) gao1(c[i]);
}

inline void gao()
{
	int id=(rnd()%n+n)%n+1;
	gao(num[id]);gao(num[id]+1);gao(num[id]-1);
}

int main()
{
	n=rd();pre_gao();
	for (int i=1;i<=n;i++) num[i]=rd();
	ans=n;
	for (int hhh=1;hhh<=30;hhh++) gao();
	printf("%lld\n",ans);
	return 0;
}