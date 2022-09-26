#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int T,n,m,k,id;
int first[MAXN];
int g[MAXN];
int deg[MAXN];

ll f[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u,int fa,ll pen)
{
	f[u] = -pen;
	g[u] = 1;
	ll v1 = -1e18;
	int cnt = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs(edge[i].to,u,pen);
			if (f[edge[i].to] >= v1 + max(f[edge[i].to],0ll))
				cnt = g[edge[i].to];
			else
				cnt += (f[edge[i].to] > 0 ? g[edge[i].to] : 0);
			v1 = max(v1 + max(f[edge[i].to],0ll),f[edge[i].to]);
		}
	if (f[u] < v1)
	{
		f[u] = v1;
		g[u] = cnt;
	}
	f[u]++;
//	cerr << "u=" << u << ' ' << f[u] << ' ' << g[u] << endl;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
		deg[u]++,deg[v]++;
	}
	int cnt = 0;
	for (int i = 2;i <= n;i++)
		if (deg[i] == 1)
			cnt++;
	ll ans = 0;
	if (cnt <= k)
	{
		for (int i = cnt;i <= k;i++)
			ans = max(ans,(ll)i * (n - i));
		printf("%lld\n",ans);
		return 0;
	}
	int low = 0,high = n;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		dfs(1,0,mid);
		if ((f[1] <= 0 ? 0 : g[1]) > k)
			low = mid + 1;
		else
			high = mid;
	}
	dfs(1,0,low);
	ans = max(0ll,f[1]) + (ll)k * low;
	ll MIN = 1e18;
	for (int j = 0;j <= n - ans;j++)
		MIN = min(MIN,(ll)(n - k - j) * (k - j));
//	cout << "!!:" << ans << ' ' << low << endl;
	printf("%lld\n",MIN);
	return 0;
}