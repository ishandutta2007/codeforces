#include<cstdio>
#include<queue>
const int MAXN = 1e6 + 5;
using namespace std;

int p[MAXN];

int fa[MAXN];
int find(int u){ return fa[u]==u? u: fa[u]=find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

priority_queue<int> q[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	for(int i=1; i<=n; ++i) fa[i]=i;
	for(int i=1; i<=m; ++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		connect(a,b);
	}
	
	for(int i=1; i<=n; ++i) q[find(i)].push(p[i]);
	for(int i=1; i<=n; ++i)
	{
		printf("%d ",q[find(i)].top());
		q[find(i)].pop();
	}
	return 0;
}