#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0, deg[MAXN];
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
	++deg[v];
}

bool vis[MAXN];
vector<int> ep;
int tot = 0;
void dfs_cnt(int u)
{
	vis[u] = 1; ++tot;
	if(deg[u] == 1) ep.push_back(u);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(!vis[v]) dfs_cnt(v);
	}
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m > n) return printf("NO"), 0;
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	if(n == m)
	{
		for(int i=1; i<=n; ++i)
			if(deg[i] != 2) return printf("NO"), 0;
		dfs_cnt(1);
		for(int i=1; i<=n; ++i)
			if(!vis[i]) return printf("NO"), 0;
		printf("YES\n0\n");
		return 0;
	}
	
	for(int i=1; i<=n; ++i)
		if(deg[i] > 2) return printf("NO"), 0;
	
	priority_queue<pii,vector<pii>,greater<pii> > q;
	
	for(int i=1; i<=n; ++i) if(!vis[i])
	{
		ep.clear();
		tot = 0;
		
		dfs_cnt(i);
		
		if(tot == 1)
		{
			if(deg[i] != 0) return printf("NO"), 0;
			q.push(make_pair(i,i));
		}
		else
		{
			if(ep.size() != 2) return printf("NO"), 0;
			if(ep[0] > ep[1]) swap(ep[0], ep[1]);
			q.push(make_pair(ep[0], ep[1]));
		}
	}
	
	printf("YES\n%d\n",n-m);
	while(q.size() > 1)
	{
		pii a = q.top(); q.pop();
		pii b = q.top(); q.pop();
		printf("%d %d\n",a.first,b.first);
		
		pii nxt = make_pair(a.second, b.second);
		if(nxt.first > nxt.second) swap(nxt.first, nxt.second);
		
		q.push(nxt);
	}
	
	pii res = q.top(); q.pop();
	if(n == 1 || res.first != res.second)
		printf("%d %d\n",res.first,res.second);
	return 0;
}