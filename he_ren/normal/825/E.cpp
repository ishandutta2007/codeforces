#include<cstdio>
#include<queue>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

struct Edge
{
	int next,to;
}e[MAXM];
int head[MAXN],in[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
	++in[v];
}

//priority_queue<int, vector<int>, greater<int> > q;
priority_queue<int> q;

int ans[MAXN],cnt;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(v,u);
	}
	
	for(int i=1; i<=n; ++i)
		if(!in[i]) q.push(i);
	
	cnt=n+1;
	while(!q.empty())
	{
		int u=q.top(); q.pop();
		ans[u] = --cnt;
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			--in[v];
			if(!in[v]) q.push(v);
		}
	}
	
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
	return 0;
}