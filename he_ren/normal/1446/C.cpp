#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int lb = 30;
const int inf = 0x3f3f3f3f;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

struct Node
{
	int son[2];
	inline int& operator [] (const int x){ return son[x];}
	inline int operator [] (const int x) const { return son[x];}
	Node(void){ son[0] = son[1] = -1;}
};
vector<Node> p(2);

inline void insert(int x)
{
	int u = 1;
	for(int i=lb; i>=0; --i)
	{
		int k = bdig(x,i);
		if(p[u][k] == -1) p[u][k] = (int)p.size(), p.push_back(Node());
		u = p[u][k];
	}
}

vector<int> siz;
int dfs_siz(int u)
{
	if(u == -1) return 0;
	if(p[u][0] == -1 && p[u][1] == -1) return siz[u] = 1;
	return siz[u] = dfs_siz(p[u][0]) + dfs_siz(p[u][1]);
}

vector<int> f, g;
void dfs_fg(int u)
{
	f[u] = g[u] = inf;
	if(p[u][0] == -1 && p[u][1] == -1)
	{
		f[u] = g[u] = 0;
		return;
	}
	
	if(p[u][0] == -1 || p[u][1] == -1)
	{
		int v = p[u][0] == -1? p[u][1]: p[u][0];
		dfs_fg(v);
		f[u] = f[v]; g[u] = g[v];
		return;
	}
	
	Node &son = p[u];
	dfs_fg(son[0]); dfs_fg(son[1]);
	
	f[u] = g[u] = inf;
	for(int k=0; k<=1; ++k)
	{
		f[u] = min(f[u], f[son[k]] + siz[son[!k]]);
		g[u] = min(g[u], f[son[k]] + g[son[!k]]);
	}
}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) insert(a[i]);
	
	siz.resize(p.size());
	dfs_siz(1);
	
	f.resize(p.size());
	g = f;
	dfs_fg(1);
	
	printf("%d",g[1]);
	return 0;
}