#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int MAXM = 5e3 + 5;

struct Edge
{
	int next,to,id;
}e[MAXM];
int head[MAXN], etot=0, deg[MAXN];
inline void add(int u,int v,int id)
{
	e[++etot] = (Edge){ head[u],v,id};
	head[u] = etot;
	++deg[v];
}

int clr[MAXM], ccnt = 1;

bool vis[MAXN], insta[MAXN];
void dfs(int u)
{
	vis[u] = insta[u] = 1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(insta[v]){ clr[e[i].id] = ccnt = 2; continue;}
		clr[e[i].id] = 1;
		if(!vis[v]) dfs(v);
	}
	insta[u] = 0;
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,i);
	}
	
	for(int i=1; i<=n; ++i)
		if(!vis[i]) dfs(i);
	
	printf("%d\n",ccnt);
	for(int i=1; i<=m; ++i) printf("%d ",clr[i]);
	return 0;
}