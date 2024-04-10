#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int LB = log(MAXM)/log(2) + 5;
using namespace std;

inline int max(int a,int b){ return a>b? a: b;}
inline void swap(int &a,int &b){ int t=a; a=b; b=t;}

int m;

struct Edge_
{
	int u,v,w,id;
}e_[MAXM],in[MAXM];
bool chs[MAXM];
inline bool cmp_(Edge_ a,Edge_ b){ return a.w<b.w;}

int fa[MAXN];
inline int find(int u){ return fa[u]? fa[u]=find(fa[u]): u;}
inline void connect(int u,int v){ fa[find(u)]=find(v);}

struct Edge
{
	int next,to,w;
}e[MAXM*2];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	++etot;
	e[etot] = (Edge){ head[u],v,w};
	head[u]=etot;
}

ll tmp=0;
inline void kruskal(void)
{
	sort(e_+1,e_+m+1,cmp_);
	for(int i=1; i<=m; ++i)
	{
		int u=e_[i].u, v=e_[i].v, w=e_[i].w;
		if(find(u)==find(v)) continue;
		
		chs[e_[i].id]=1;
		connect(u,v);
		add(u,v,w); add(v,u,w);
		tmp+=(ll)w;
	}
}

int lb[MAXM];
int f[MAXN][LB],dep[MAXN];
int g[MAXN][LB];
void lca_init(int u)
{
	for(int i=1; i<=lb[dep[u]]; ++i)
		f[u][i] = f[f[u][i-1]][i-1],
		g[u][i] = max(g[u][i-1], g[f[u][i-1]][i-1]);
	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==f[u][0]) continue;
		
		dep[v] = dep[u]+1;
		f[v][0]=u; g[v][0]=e[i].w;
		lca_init(v);
	}
}

int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	
	int ans=0;
	for(int i=lb[dep[u]]; i>=0 && dep[u]>dep[v]; --i)
		if(dep[f[u][i]] >= dep[v])
			ans = max(ans, g[u][i]),
			u=f[u][i];
	
	if(u==v) return ans;
	for(int i=lb[dep[u]]; i>=0 && f[u][0]!=f[v][0]; --i)
		if(f[u][i]!=f[v][i])
		{
			ans = max(ans, g[u][i]);
			ans = max(ans, g[v][i]);
			u = f[u][i];
			v = f[v][i];
		}
	
	ans = max(ans,g[u][0]);
	ans = max(ans,g[v][0]);
	
	return ans;
}

int main(void)
{	
	int n;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
		scanf("%d%d%d",&e_[i].u,&e_[i].v,&e_[i].w),
		e_[i].id=i,
		in[i] = e_[i];
	kruskal();
	
	lb[1]=1;
	for(int i=2; i<=m; ++i) lb[i] = lb[i/2]+1;
	dep[1]=1;
	lca_init(1);
	
	for(int i=1; i<=m; ++i)
	{
		if(chs[i]) cout<<tmp<<endl;
		else cout<<tmp-lca(in[i].u,in[i].v)+in[i].w<<endl;
	}
	return 0;
}