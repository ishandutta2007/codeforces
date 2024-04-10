#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

struct node { int t,next; }a[2000010];

unordered_map<ll,int> mp;

ll sum[1000010];
ll h[100010],f[100010];
ll head[1000010],num[1000010],fa[1000010],d[100010],n,tt,tot;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline void add(const int &x,const int &y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline ll gcd(ll x,ll y) { return (!y)?x:gcd(y,x%y); }

inline void pre_dfs(int x,int y)
{
	sum[x]=num[x];
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		pre_dfs(t,x);
		sum[x]+=sum[t];
	}
}

inline void dfs(int x,int y)
{
	h[mp[gcd(sum[x],sum[1])]]++;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dfs(t,x);
	}
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=2;i<=n;i++) fa[i]=rd(),add(i,fa[i]),add(fa[i],i);
	pre_dfs(1,0);
	ll s=sum[1];
	tt=0;
	for (ll i=1;i*i<=s;i++)
	{
		if (s%i==0)
		{
			num[++tt]=i;
			if (i*i!=s) num[++tt]=s/i;
		}
	}
	sort(num+1,num+tt+1);
	for (int i=1;i<=tt;i++) mp[num[i]]=i;
	dfs(1,0);
	for (int i=1;i<=tt;i++) for (int j=i+1;j<=tt;j++) if (num[j]%num[i]==0) h[i]+=h[j];
	f[tt]=1;
	for (int i=tt-1;i;i--) if (h[i]==sum[1]/num[i])
	{
		for (int j=i+1;j<=tt;j++) if (num[j]%num[i]==0) f[i]=pls(f[i],f[j]);
	}
	ll ans=0;
	for (int i=1;i<=tt;i++) ans=pls(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}