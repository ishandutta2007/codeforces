#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int LB = 20 + 3;
const int inf = 0x3f3f3f3f;

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

int f[MAXN];

void dfs_f(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		f[v] = min(f[u], v);
		dfs_f(v,u);
	}
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
	
	--Q;
	int rt;
	scanf("%*d%d",&rt); rt = rt % n + 1;
	f[rt] = rt;
	dfs_f(rt, 0);
	
	int lst = 0, cur = f[rt];
	while(Q--)
	{
		int op,u;
		scanf("%d%d",&op,&u);
		u = (u + lst) % n + 1;
		
		if(op == 1) cur = min(cur, f[u]);
		else
		{
			int ans = min(cur, f[u]);
			printf("%d\n",ans);
			lst = ans;
		}
	}
	return 0;
}