#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

struct node { int t,next; }a[400010];

ll fac[200010];
int head[200010],size[200010],n,tot;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline ll dfs(int x,int y)
{
	int son=0;
	ll res=1;size[x]=1;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		res=res*dfs(t,x)%mod;
		son++;size[x]+=size[t];
	}
	if (!son) return 1;
	return fac[son]*res%mod*(son+1)%mod;
}

int main()
{
	n=rd();tot=0;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x); }
	int hh=0;
	for (int i=head[1];i;i=a[i].next) hh++;
	printf("%lld\n",dfs(1,0)*ksm(hh+1,mod-2)%mod*n%mod);
	return 0;
}