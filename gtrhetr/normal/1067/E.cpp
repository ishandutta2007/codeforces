#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

struct node { int t,next; }a[1000010];

ll f[500010][2],h[500010][2];
int head[500010],n,tot;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

const ll inv2=ksm(2,mod-2);

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void dfs(int x,int y)
{
	h[x][0]=1;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dfs(t,x);
		ll h1=f[x][0],h2=f[x][1];
		f[x][0]=pls(pls(h1*h[t][0]%mod,f[t][0]*h[x][0]%mod)%mod,pls(h1*h[t][1]%mod,f[t][1]*h[x][0]%mod)*2%mod);
		f[x][1]=pls(pls(pls(h2*h[t][0]%mod,f[t][0]*h[x][1]%mod)%mod,pls(h2*h[t][1]%mod,f[t][1]*h[x][1]%mod)%mod)*2%mod,pls(pls(h1*h[t][0]%mod,f[t][0]*h[x][0]%mod),h[x][0]*h[t][0]%mod)%mod);
		ll hh=h[x][0];
		h[x][0]=pls(pls(h[x][0]*h[t][0]%mod,h[x][0]*h[t][1]%mod),h[x][0]*h[t][1]%mod);
		h[x][1]=pls(h[x][1]*pls(h[t][0],h[t][1])%mod*2%mod,hh*h[t][0]%mod);
	}
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x); }
	dfs(1,0);
	ll ans=pls(f[1][0],f[1][1]);
	ans=ans*2%mod;
	printf("%lld\n",ans);
	return 0;
}