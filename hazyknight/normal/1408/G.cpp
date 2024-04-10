#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1505;
const ll MOD = 998244353;

int n,id;
int fa[MAXN];
int mem[MAXN];
int cnt[MAXN];
int sz[MAXN];
int s[MAXN << 1];

ll g[MAXN];
ll f[MAXN << 1][MAXN];

bool vis[MAXN << 1];

vector<pair<int,int> > t[MAXN * MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		for (int a,j = 1;j <= n;j++)
		{
			scanf("%d",&a);
			if (i < j)
				t[a].push_back(make_pair(i,j));
		}
	for (int i = 1;i <= n;i++)
	{
		fa[i] = i;
		mem[i] = i;
		cnt[i] = 0;
		sz[i] = 1;
		s[i] = 1;
		f[i][1] = 1;
	}
	id = n;
	for (int i = 0;i <= n * (n - 1) / 2;i++)
		for (int j = 0;j < t[i].size();j++)
		{
			int u = t[i][j].first,v = t[i][j].second;
			int ru = getroot(u),rv = getroot(v);
			if (ru == rv)
				cnt[ru]++;
			else
			{
				cnt[rv] += cnt[ru] + 1;
				sz[rv] += sz[ru];
				fa[ru] = rv;
			}
			ru = getroot(u);
			if (sz[ru] * (sz[ru] - 1) / 2 == cnt[ru])
			{
				id++;
				vector<int> c;
				for (int k = 1;k <= n;k++)
					if (getroot(k) == ru)
					{
						if (!vis[mem[k]])
						{
							c.push_back(mem[k]);
							vis[mem[k]] = 1;
						}
						mem[k] = id;
					}
				f[id][0] = 1;
				for (int k = 0;k < c.size();k++)
				{
					for (int l = 0;l <= s[id] + s[c[k]];l++)
						g[l] = 0;
					for (int l = 0;l <= s[id];l++)
						for (int o = 0;o <= s[c[k]];o++)
							(g[l + o] += f[id][l] * f[c[k]][o]) %= MOD;
					s[id] += s[c[k]];
					for (int l = 0;l <= s[id];l++)
						f[id][l] = g[l];
				}
				(f[id][1] += 1) %= MOD;
			}
		}
	for (int i = 1;i <= n;i++)
		printf("%lld ",f[id][i]);
	printf("\n");
	return 0;
}