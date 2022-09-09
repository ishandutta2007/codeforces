#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

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

int n;
int p[MAXM];
ll sum[MAXM];

void bfs(int s,int dis[])
{
	static queue<int> q;
	for(int i=1; i<=n; ++i) dis[i]=-1;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			if(dis[v]==-1)
				dis[v]=dis[u]+1, q.push(v);
		}
	}
}

int disA[MAXN],disB[MAXN],disC[MAXN];

void solve(void)
{
	int m,a,b,c;
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	for(int i=1; i<=m; ++i) scanf("%d",&p[i]);
	etot=0;
	for(int i=1; i<=n; ++i) head[i]=0;
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	sort(p+1,p+m+1);
	for(int i=1; i<=m; ++i) sum[i] = sum[i-1] + p[i];
	
	bfs(a,disA); bfs(b,disB); bfs(c,disC);
	
	ll ans = linf;
	for(int i=1; i<=n; ++i)
	{
		if(disA[i] + disB[i] + disC[i] > m) continue;
		ll tmp = sum[ disA[i] + disB[i] + disC[i] ] + sum[ disB[i] ];
		ans = min(ans, tmp);
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