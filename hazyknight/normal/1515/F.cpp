#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

int n,m,x;
int a[MAXN];
int fa[MAXN];

ll s[MAXN];

vector<pair<int,int> > e[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int main()
{
	scanf("%d%d%d",&n,&m,&x);
	ll sum = 0;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if (sum < (ll)(n - 1) * x)
	{
		puts("NO");
		return 0;
	}
	for (int i = 1;i <= n;i++)
		fa[i] = i;
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		int ru = getroot(u),rv = getroot(v);
		if (ru != rv)
		{
			e[u].push_back(make_pair(v,i));
			e[v].push_back(make_pair(u,i));
			fa[ru] = rv;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		fa[i] = i;
		s[i] = a[i];
	}
	puts("YES");
	for (int i = 1;i <= n;i++)
	{
		while (1)
		{
			int u = getroot(i);
			if (s[u] < x)
				break;
			while (e[u].size() && getroot(e[u].back().first) == u)
				e[u].pop_back();
			if (!e[u].size())
				break;
			
			printf("%d\n",e[u].back().second);
			int v = getroot(e[u].back().first);
			if (e[u].size() < e[v].size())
				swap(u,v);
			s[u] += s[v] - x;
			for (int i = 0;i < e[v].size();i++)
				if (getroot(e[v][i].first) != u)
					e[u].push_back(e[v][i]);
			fa[v] = u;
		}
	}
	for (int i = 1;i <= n;i++)
		if (getroot(i) == i)
			for (int j = 0;j < e[i].size();j++)
				if (getroot(e[i][j].first) > i)
					printf("%d\n",e[i][j].second);
	return 0;
}