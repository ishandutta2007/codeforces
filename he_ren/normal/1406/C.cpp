#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN], etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int n;
int size[MAXN];

vector<int> cen;

pii dfs_leaf(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		return dfs_leaf(v, u);
	}
	return make_pair(u, fa);
}

void dfs_size(int u,int fa)
{
	size[u] = 1;
	int mx = 0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_size(v,u);
		size[u] += size[v];
		mx = max(mx, size[v]);
	}
	mx = max(mx, n - size[u]);
	
	if(mx <= n/2) cen.push_back(u);
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
	
	cen.clear();
	dfs_size(1,0);
	if(cen.size() == 1)
	{
		int v = e[head[1]].to;
		printf("%d %d\n%d %d\n",1,v,1,v);
		return;
	}
	
	int u = cen[0];
	pii res = dfs_leaf(cen[1], cen[0]);
	printf("%d %d\n",res.first,res.second);
	printf("%d %d\n",u,res.first);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}