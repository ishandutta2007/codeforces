#include<cstdio>
#include<vector>
using namespace std;
typedef unsigned int uint;
const int MAXN = 1e6 + 5;

inline void swap(int &a,int &b){ int t=a; a=b; b=t;}

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int ans[MAXN];
vector<int> d[MAXN];
int mx[MAXN],p[MAXN];

inline void merge(int u,int v)//d[u] to d[v]
{
	int beg = d[v].size()-d[u].size();
	for(uint i=0; i<d[u].size(); ++i)
	{
		d[v][beg+i]+=d[u][i];
		if(d[v][beg+i]>=d[v][mx[v]]) mx[v]=beg+i;
	}
	d[u].clear();
}

inline void dfs(int u,int fa)
{
	p[u]=u;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
		
		if(d[p[u]].size()<d[p[v]].size()) swap(p[u],p[v]);
		merge(p[v],p[u]);
	}
	
	vector<int> &du=d[p[u]];
	int &mxu=mx[p[u]];
	
	du.push_back(1);
	if(du[mxu]<=1) mxu=du.size()-1;
	ans[u]=du.size()-mxu-1;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	for(int i=1; i<=n; ++i)
		printf("%d\n",ans[i]);
	return 0;
}