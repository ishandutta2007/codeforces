#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 5e3 + 5;
const int MAXM = 1e5 + 5;

inline void error(void){ printf("NO"); exit(0);}

struct Edge
{
	int next,to;
}e[MAXM<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

vector<int> a[MAXN];
int tot=0, c[MAXN][2];

int clr[MAXN];
void dfs(int u)
{
	a[tot].push_back(u);
	++c[tot][clr[u]];
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(clr[v]==-1) clr[v]=clr[u]^1, dfs(v);
		else if(clr[v] == clr[u]) error();
	}
}

bool f[MAXN][MAXN], g[MAXN][MAXN];

int ans[MAXN];

int main(void)
{
	memset(clr,-1,sizeof(clr));
	
	int n,m;
	scanf("%d%d",&n,&m);
	int n1,n2,n3;
	scanf("%d%d%d",&n1,&n2,&n3);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	for(int i=1; i<=n; ++i)
	{
		if(~clr[i]) continue;
		
		++tot;
		clr[i]=0;
		dfs(i);
	}
	
	f[0][0] = 1;
	for(int i=1; i<=tot; ++i)
		for(int j=0; j<=n2; ++j)
		{
			if(!f[i-1][j]) continue;
			
			if(j + c[i][0] <= n2) f[i][j + c[i][0]] = 1, g[i][j + c[i][0]] = 0;
			if(j + c[i][1] <= n2) f[i][j + c[i][1]] = 1, g[i][j + c[i][1]] = 1;
		}
	
	if(!f[tot][n2]) error();
	
	int now = n2;
	for(int i=tot; i>=1; --i)
	{
		int cc = g[i][now];
		for(int j=0; j<(int)a[i].size(); ++j)
		{
			int u = a[i][j];
			if(clr[u] == cc) ans[u] = 2;
			else
			{
				if(n1) ans[u] = 1, --n1;
				else ans[u] = 3, --n3;
			}
		}
		now -= c[i][cc];
	}
	
	printf("YES\n");
	for(int i=1; i<=n; ++i) printf("%d",ans[i]);
	return 0;
}