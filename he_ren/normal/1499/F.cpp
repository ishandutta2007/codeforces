#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

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

int n,d;

int f[MAXN][MAXN];
void dfs_f(int u,int fa)
{
	f[u][0] = 1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_f(v,u);
		
		static int fu[MAXN];
		for(int j=0; j<=d; ++j) fu[j] = f[u][j];
		
		static int pu[MAXN], pv[MAXN];
		pu[0] = f[u][0]; pv[0] = f[v][0];
		for(int j=1; j<=d; ++j)
			add_mod(pu[j] = pu[j-1], f[u][j]),
			add_mod(pv[j] = pv[j-1], f[v][j]);
		
		int sum = 0;
		for(int j=0; j<=d; ++j) add_mod(sum, f[v][j]);
		for(int j=0; j<=d; ++j)
			f[u][j] = (ll)f[u][j] * sum %mod;
		
		for(int j=0; j<d; ++j)
			f[u][j+1] = (f[u][j+1] + (ll)pu[min(j+1, d-j-1)] * f[v][j]) %mod;
		
		for(int j=2; j<d; ++j)
			f[u][j] = (f[u][j] + (ll)pv[min(j-2, d-j-1)] * fu[j]) %mod;
	}
}

int main(void)
{
	scanf("%d%d",&n,&d);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_f(1,0);
	
	int ans = 0;
	for(int i=0; i<=d; ++i) add_mod(ans, f[1][i]);
	printf("%d",ans);
	return 0;
}