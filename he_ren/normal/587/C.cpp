#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1e5 + 5;
const int LB = 16 + 5;
const int inf = 0x3f3f3f3f;

inline int min(int a,int b){ return a<b? a: b;}
inline void chk_min(int &a,int b){ if(a>b) a=b;}

struct Edge
{
	int next,to;
}e[MAXN*2];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u]=etot;
}

int lb[MAXN];
int dep[MAXN], fa[MAXN][LB];
vector<int> g[MAXN][LB];

inline void merge(vector<int> &u,const vector<int> &v,const vector<int> w)
{
	u.clear();
	unsigned int i=0,j=0;
	while(u.size()<10 && i<v.size() && j<w.size())
	{
		if(v[i] <= w[j]) u.push_back(v[i++]);
		else u.push_back(w[j++]);
	}
	while(u.size()<10 && i<v.size()) u.push_back(v[i++]);
	while(u.size()<10 && j<w.size()) u.push_back(w[j++]);
}

void lca_init(int u,int pre)
{
	for(int i=1; i<=lb[dep[u]]; ++i)
	{
		fa[u][i] = fa[fa[u][i-1]][i-1];
		merge(g[u][i], g[fa[u][i-1]][i-1], g[u][i-1]);
	}
	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==pre) continue;
		fa[v][0] = u;
		dep[v]=dep[u]+1;
		lca_init(v,u);
	}
}

inline void chk_merge(vector<int> &u, const vector<int> &v)
{
	vector<int> tmp;
	merge(tmp, u,v);
	u=tmp;
}

vector<int> ans;
void lca(int u,int v)
{
	ans.clear();
	if(dep[u]<dep[v]) swap(u,v);
	
	for(int i=lb[dep[u]]; dep[u]>dep[v] && i>=0; --i)
		if(dep[fa[u][i]] >= dep[v])
		{
			chk_merge(ans, g[u][i]);
			u=fa[u][i];
		}
	
	if(u==v)
	{
		chk_merge(ans, g[u][0]);
		return;
	}
	
	for(int i=lb[dep[u]]; i>=0 && fa[u][0]!=fa[v][0]; --i)
		if(fa[u][i] != fa[v][i])
		{
			chk_merge(ans, g[u][i]);
			chk_merge(ans, g[v][i]);
			u=fa[u][i];
			v=fa[v][i];
		}
	chk_merge(ans, g[u][0]);
	chk_merge(ans, g[v][0]);
	chk_merge(ans, g[fa[u][0]][0]);
}

int main(void)
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i=1; i<=m; ++i)
	{
		int c;
		scanf("%d",&c);
		g[c][0].push_back(i);
	}
	
	for(int i=1; i<=n; ++i)
	{
		sort(g[i][0].begin(), g[i][0].end());
		if(g[i][0].size()>10)
			g[i][0].resize(10);
	}
	
	for(int i=2; i<=n; ++i) lb[i]=lb[i>>1]+1;
	dep[1]=1;
	lca_init(1,0);
	
	while(q--)
	{
		int u,v,a;
		scanf("%d%d%d",&u,&v,&a);
		lca(u,v);
		chk_min(a, ans.size());
		printf("%d ",a);
		for(int i=0; i<a; ++i) printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}