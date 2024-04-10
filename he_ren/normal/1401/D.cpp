#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 6e4 + 5;
const int mod = 1e9 + 7;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int n;
int p[MAXM];

int size[MAXN];
vector<ll> f;

void dfs_size(int u,int fa)
{
	size[u] = 1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v==fa) continue;
		dfs_size(v,u);
		size[u] += size[v];
		
		f.push_back((ll)size[v] * (n-size[v]));
	}
}

void solve(void)
{
	scanf("%d",&n);
	etot = 0;
	for(int i=1; i<=n; ++i) head[i] = 0;
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i) scanf("%d",&p[i]);
	
	f.clear();
	dfs_size(1,0);
	
	sort(f.begin(), f.end());
	reverse(f.begin(), f.end());
	sort(p+1,p+m+1);
	reverse(p+1,p+m+1);
	
	if(m <= n-1)
	{
		ll ans = 0;
		for(int i=1; i<=m; ++i)
			ans = (ans + f[i-1] * p[i]) %mod;
		for(int i=m+1; i<=n-1; ++i)
			ans = (ans + f[i-1]) %mod;
		printf("%lld\n",ans);
	}
	else
	{
		ll ans = 0;
		int more = m - (n-1);
		for(int i=1; i<=more; ++i)
			p[more+1] = (ll)p[more+1] * p[i] %mod;
		for(int i=1; i<=n-1; ++i)
			ans = (ans + f[i-1] * p[i+more]) %mod;
		printf("%lld\n",ans);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}