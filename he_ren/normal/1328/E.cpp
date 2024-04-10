#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int LB = 20 + 5;

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

int lb[MAXN],dep[MAXN],fa[MAXN][LB];

void lca_init(int u,int pre)
{
	for(int i=1; i<=lb[dep[u]]; ++i)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==pre) continue;
		dep[v]=dep[u]+1;
		fa[v][0]=u;
		lca_init(v,u);
	}
}

int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=lb[dep[u]]; dep[u]>dep[v]; --i)
		if(dep[fa[u][i]] >= dep[v])
			u=fa[u][i];
	if(u==v) return u;
	for(int i=lb[dep[u]]; fa[u][0]!=fa[v][0]; --i)
		if(fa[u][i] != fa[v][i])
			u=fa[u][i],
			v=fa[v][i];
	return fa[u][0];
}

struct Node
{
	int id,dep;
}q[MAXN];
bool cmp(const Node &p,const Node &q){ return p.dep<q.dep;}

int p[MAXN];

void solve(void)
{
	int d;
	scanf("%d",&d);
	for(int i=1; i<=d; ++i)
		scanf("%d",&q[i].id),
		q[i].dep = dep[q[i].id];
	
	sort(q+1,q+d+1,cmp);
	//for(int i=1; i<=d; ++i) printf("%d ",q[i].id);
	
	for(int i=1; i<=d; ++i) p[i] = q[i].id;
	
	int lst=1;
	for(int i=1,j=1; i<=d; i=j)
	{
		while(j<=d && q[i].dep==q[j].dep) ++j;
		if(q[i].dep==0) continue;
		
		int now = fa[p[i]][0];
		
		for(int k=i; k<j; ++k)
		{
			if(p[k]==p[i]) continue;
			if(lca(p[k],p[i]) != now){ printf("NO\n"); return;}
		}
		
		if(lca(now,lst) != lst){ printf("NO\n"); return;}
		lst=now;
	}
	printf("YES\n");
}

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	lb[1]=0;
	for(int i=2; i<=n; ++i) lb[i] = lb[i>>1]+1;
	dep[0]=-1;
	lca_init(1,0);
	
	while(Q--) solve();
	return 0;
}