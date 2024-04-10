#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int T,n,m,k,tot;
int deg[MAXN];
int a[MAXN];

bool vis[MAXN];

vector<int> e[MAXN];
unordered_map<int,bool> E[MAXN];

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for (int i = 1;i <= n;i++)
		{
			e[i].clear();
			E[i].clear();
			deg[i] = vis[i] = 0;
		}
		while (!Q.empty())
			Q.pop();
		for (int u,v,i = 1;i <= m;i++)
		{
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
			E[u][v] = E[v][u] = 1;
			deg[u]++;
			deg[v]++;
		}
		for (int i = 1;i <= n;i++)
			Q.push(make_pair(deg[i],i));
		bool gg = 0;
		while (!Q.empty())
		{
			int u = Q.top().second;
			Q.pop();
			if (vis[u])
				continue;
			bool killed = 0;
			if (deg[u] == k - 1)
			{
				bool ok = 1;
				if ((ll)k * (k - 1) / 2 <= m)
				{
					tot = 0;
					for (int i = 0;i < e[u].size();i++)
					{
						int to = e[u][i];
						if (!vis[to])
							a[++tot] = to;
					}
					for (int i = 1;ok && i <= tot;i++)
						for (int j = i + 1;ok && j <= tot;j++)
							if (!E[a[i]][a[j]])
								ok = 0;
				}
				else
					ok = 0;
				if (ok)
				{
					printf("2\n%d ",u);
					for (int i = 0;i < e[u].size();i++)
					{
						int to = e[u][i];
						if (!vis[to])
							printf("%d ",to);
					}
					printf("\n");
					gg = 1;
					break;
				}
				killed = 1;
			}
			if (deg[u] < k - 1 || killed)
			{
				for (int i = 0;i < e[u].size();i++)
				{
					int to = e[u][i];
					if (!vis[to])
					{
						deg[to]--;
						Q.push(make_pair(deg[to],to));
					}
				}
			}
			if (deg[u] >= k)
			{
				int tot = 0;
				for (int i = 1;i <= n;i++)
					if (!vis[i])
						tot++;
				printf("1 %d\n",tot);
				for (int i = 1;i <= n;i++)
					if (!vis[i])
						printf("%d ",i);
				printf("\n");
				gg = 1;
				break;
			}
			vis[u] = 1;
		}
		if (!gg)
			puts("-1");
	}
	return 0;
}