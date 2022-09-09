#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int MAXN = 1e5 + 5;

struct Edge
{
	int next,to,w;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	e[++etot] = (Edge){ head[u],v,w};
	head[u]=etot;
}

priority_queue<pli> q;
int val[MAXN], cnt[MAXN], cur = 0;

int size[MAXN];
void dfs_size(int u,int fa)
{
	size[u] = 0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		
		dfs_size(v,u);
		size[u] += size[v];
		
		++cur;
		val[cur] = e[i].w;
		cnt[cur] = size[v];
	}
	if(!size[u]) size[u] = 1;
}

void solve(void)
{
	while(!q.empty()) q.pop();
	
	int n;
	ll s;
	scanf("%d%lld",&n,&s);
	etot = 0;
	for(int i=1; i<=n; ++i) head[i] = 0;
	for(int i=1; i<n; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	
	cur = 0;
	dfs_size(1,0);
	
	ll rem = 0;
	for(int i=1; i<=cur; ++i)
		q.push(make_pair((ll)(val[i]+1)/2 * cnt[i], i)),
		rem += (ll)val[i] * cnt[i];
	
	int ans = 0;
	while(rem > s)
	{
		pli top = q.top(); q.pop();
		
		int x = top.second;
		++ans;
		rem -= top.first;
		
		val[x]/=2;
		if(val[x]) q.push(make_pair((ll)(val[x]+1)/2 * cnt[x], x));
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}

/*
1
5 50
1 3 100
1 5 10
2 3 123
5 4 55
*/