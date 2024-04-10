#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 4e3 + 5;
const int MAXM = 2e3 + MAXN;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

struct Edge
{
	int next,to,flow;
}e[MAXM<<1];
int head[MAXN],etot=-1,deg[MAXN];
inline void add(int u,int v,int flow)
{
	e[++etot]=(Edge){ head[u],v,flow};
	head[u]=etot;
	++deg[v];
}
inline void addEdge(int u,int v,int flow)
{
	add(u,v,flow); add(v,u,0);
}

int n,s,t;

int dep[MAXN],cur[MAXN];
bool bfs(void)
{
	static queue<int> q;
	for(int i=1; i<=n; ++i)
		dep[i]=-1, cur[i]=head[i];
	dep[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=head[u]; ~i; i=e[i].next)
			if(dep[e[i].to]==-1 && e[i].flow)
				dep[e[i].to]=dep[u]+1,
				q.push(e[i].to);
	}
	return ~dep[t];
}

int dfs(int u,int minf)
{
	if(u==t || !minf) return minf;
	int res=0;
	for(int f,&i=cur[u]; ~i; i=e[i].next)
	{
		int v=e[i].to;
		if(dep[v]==dep[u]+1 && (f=dfs(v,min(minf,e[i].flow))))
		{
			res+=f; minf-=f;
			e[i].flow-=f;
			e[i^1].flow+=f;
			if(!minf) return res;
		}
	}
	return res;
}

int dinic(void)
{
	int res=0;
	while(bfs())
		res += dfs(s,inf);
	return res;
}

vector<int> ans[MAXM]; 

int main(void)
{
	memset(head,-1,sizeof(head));
	
	int n1,n2,m;
	scanf("%d%d%d",&n1,&n2,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,n1+v,1);
	}
	s=n1+n2+1; t=n1+n2+2;
	n=t;
	
	int minDeg = inf;
	for(int i=1; i<=n1+n2; ++i)
		chk_min(minDeg, deg[i]);
	
	for(int i=1; i<=n1; ++i)
		addEdge(s,i,deg[i]-minDeg);
	for(int i=1; i<=n2; ++i)
		addEdge(n1+i,t,deg[n1+i]-minDeg);
	
	for(int k=minDeg; k>=0; --k)
	{
		dinic();
		for(int i=0; i<m; ++i)
			if(e[i<<1].flow) ans[k].push_back(i+1);
		
		for(int i=head[s]; ~i; i=e[i].next)
			++e[i].flow;
		for(int i=head[t]; ~i; i=e[i].next)
			++e[i^1].flow;
	}
	
	for(int i=0; i<=minDeg; ++i)
	{
		printf("%d ",(int)ans[i].size());
		for(int j=0; j<(int)ans[i].size(); ++j)
			printf("%d ",ans[i][j]);
		putchar('\n');
	}
	return 0;
}