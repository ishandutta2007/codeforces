#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

struct node { int t,next; }a[200010];

ll f[200010][2];
int head[200010],fa[200010],d[200010],n,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline void dfs(int x)
{
	if (!d[x]) { f[x][0]=f[x][1]=1;return; }
	ll h1=1,h2=1;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		dfs(t);
		h1=h1*f[t][0]%mod;
		h2=h2*pls(f[t][0],f[t][1])%mod;
	}
	f[x][0]=h2;
	f[x][1]=mns(h2,h1);
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		f[x][0]=mns(f[x][0],h1*ksm(f[t][0],mod-2)%mod*f[t][1]%mod);
	}
}

int main()
{
	n=rd();tot=0;
	for (int i=2;i<=n;i++) fa[i]=rd(),d[fa[i]]++;
	for (int i=2;i<=n;i++) add(fa[i],i);
	dfs(1);
	printf("%lld\n",f[1][0]);
	return 0;
}