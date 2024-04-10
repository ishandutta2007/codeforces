#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150005;
const int MAXM = 1000005;

int n,q,tot,id;
int a[MAXN];
int p[MAXN];
int fa[MAXM];
int bel[MAXM];
int bel2[MAXM];
int match[MAXM];

bool mark[MAXM];
bool vis[MAXM];

vector<int> d[MAXM];

map<int,bool> G[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void init()
{
	int N = 1000001;
	for (int i = 2;i <= N;i++)
		if (vis[i])
			fa[i] = i;
	for (int i = 2;i <= N;i++)
	{
		if (!mark[i])
		{
			p[++tot] = i;
			int rt = 0;
			for (int j = i;j <= N;j += i)
			{
				d[j].push_back(i);
				mark[j] = 1;
				if (vis[j])
				{
					if (!rt)
						rt = getroot(j);
					else
						fa[getroot(j)] = rt;
				}
			}
		}
	}
	for (int i = 2;i <= N;i++)
		if (vis[i] && !match[getroot(i)])
			match[getroot(i)] = ++id;
	for (int i = 2;i <= N;i++)
		if (vis[i])
			bel[i] = match[getroot(i)];
	for (int i = 1;i <= tot;i++)
		for (int j = p[i];j <= N;j += p[i])
			if (vis[j])
				bel2[p[i]] = bel[j];
	for (int i = 2;i <= N;i++)
		if (vis[i])
		{
			vector<int> tt;
			tt.push_back(bel[i]);
			for (int k = 0;k < d[i + 1].size();k++)
			{
				int cur = d[i + 1][k];
				if (bel2[cur])
					tt.push_back(bel2[cur]);
			}
			for (int k = 0;k < tt.size();k++)
				for (int l = k;l < tt.size();l++)
					G[tt[k]][tt[l]] = G[tt[l]][tt[k]] = 1;
		}
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		vis[a[i]] = 1;
	}
	init();
	while (q--)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		s = bel[a[s]];
		t = bel[a[t]];
		if (s == t)
			puts("0");
		else if (G[s][t] || G[t][s])
			puts("1");
		else
			puts("2");
	}
	return 0;
}