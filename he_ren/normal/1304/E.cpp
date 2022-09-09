#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1e5 + 5;

int lb[MAXN];

vector<int> g[MAXN];

int fa[MAXN][20],dep[MAXN];
void init(int u,int pre)
{
	for(int i=1; i<=lb[dep[u]]; ++i)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v=g[u][i];
		if(v==pre) continue;
		fa[v][0]=u;
		dep[v]=dep[u]+1;
		init(v,u);
	}
}

int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	int res=0;
	for(int i=lb[dep[u]]; i>=0 && dep[u]>dep[v]; --i)
		if(dep[fa[u][i]] >= dep[v])
			u=fa[u][i],
			res += 1<<i;
	if(u==v) return res;
	for(int i=lb[dep[u]]; i>=0 && fa[u][0] != fa[v][0]; --i)
		if(fa[u][i] != fa[v][i])
		{
			u=fa[u][i];
			v=fa[v][i];
			res += 1<<(i+1);
		}
	return res+2;
}

int main(void)
{
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1]+1;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dep[0]=-1;
	init(1,0);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int x,y,a,b,k;
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		
		int dis = lca(a,b);
		if(dis<=k && (dis&1)==(k&1)){ printf("YES\n"); continue;}
		
		dis = lca(a,x) + 1 + lca(y,b);
		if(dis<=k && (dis&1)==(k&1)){ printf("YES\n"); continue;}
		
		dis = lca(b,x) + 1 + lca(y,a);
		if(dis<=k && (dis&1)==(k&1)){ printf("YES\n"); continue;}
		
		printf("NO\n");
	}
	return 0;
}