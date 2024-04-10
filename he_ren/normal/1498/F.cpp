#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXD = 20 + 5;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int d;
int a[MAXN];

struct Data
{
	int f[MAXD][2];
	inline int* operator [] (const int x){ return f[x];}
	inline const int* operator [] (const int x) const { return f[x];}
	
	inline void shift(void)
	{
		for(int i=d; i>0; --i)
			f[i][0] = f[i-1][0], f[i][1] = f[i-1][1];
		f[0][0] = f[d][1]; f[0][1] = f[d][0];
	}
	inline void shift_back(void)
	{
		f[d][1] = f[0][0]; f[d][0] = f[0][1];
		for(int i=0; i<d; ++i)
			f[i][0] = f[i+1][0], f[i][1] = f[i+1][1];
	}
	inline void operator ^= (Data &g)
	{
		g.shift();
		for(int i=0; i<d; ++i)
			f[i][0] ^= g[i][0], f[i][1] ^= g[i][1];
		g.shift_back();
	}
	inline int get(void) const
	{
		int res = 0;
		for(int i=0; i<d; ++i) res ^= f[i][1];
		return res;
	}
}f[MAXN];

void dfs_up(int u,int fa)
{
	f[u][0][0] = a[u];
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_up(v,u);
		
		f[u] ^= f[v];
	}
}

void dfs_down(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		
		Data tmp = f[u];
		tmp ^= f[v];
		f[v] ^= tmp;
		
		dfs_down(v,u);
	}
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&d);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	dfs_up(1,0); dfs_down(1,0);
	
	for(int i=1; i<=n; ++i)
		printf("%d ",f[i].get()? 1: 0);
	return 0;
}