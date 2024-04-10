#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 205;
const ll MOD = 1000000007;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,id,tot;
int first[MAXN];
int vis[MAXN];

ll ans;
ll f[MAXN][MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

bool markpath(int u,int fa,int T,int len)
{
	if (u == T)
	{
		tot = len;
		vis[T] = len;
		return 1;
	}
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && markpath(edge[i].to,u,T,len + 1))
		{
			vis[u] = len;
			return 1;
		}
	return 0;
}

int getsize(int u,int fa)
{
	int sz = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && vis[edge[i].to] == -1)
			sz += getsize(edge[i].to,u);
	return sz;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		f[0][i] = 1,f[i][0] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			f[i][j] = ((MOD + 1) / 2) * (f[i - 1][j] + f[i][j - 1]) % MOD;
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j < i;j++)
		{
			memset(vis,-1,sizeof(vis));
			tot = 0;
			markpath(i,0,j,0);
			ll tmp = ans;
			for (int k = 1;k <= n;k++)
				if (~vis[k])
					(ans += (ll)getsize(k,0) * f[vis[k]][tot - vis[k]]) %= MOD;
		}
	printf("%lld\n",ans * power(n,MOD - 2) % MOD);
	return 0;
}