#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;
const int mod = 998244353;

inline ll pw(ll a,int b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

struct Edge
{
	int next,to;
}e[MAXM<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

bool vis[MAXN],clr[MAXN];
int cnt[2];
bool dfs(int u)
{
	++cnt[clr[u]];
	bool res=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(vis[v])
		{
			if(clr[u]==clr[v]) res=0;
			continue;
		}
		clr[v]=!clr[u]; vis[v]=1;
		res&=dfs(v);
	}
	return res;
}

int calc(int s)
{
	cnt[0]=cnt[1]=0;
	clr[s]=0; vis[s]=1;
	
	if(!dfs(s)) return 0;
	return (pw(2,cnt[0]) + pw(2,cnt[1])) %mod;
}

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1; i<=n; ++i) head[i]=0;
	etot=0;
	
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	for(int i=1; i<=n; ++i) vis[i]=0;
	ll ans=1;
	for(int i=1; i<=n; ++i)
		if(!vis[i])
		{
			ans = ans*calc(i) %mod;
			if(!ans) break;
		}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}