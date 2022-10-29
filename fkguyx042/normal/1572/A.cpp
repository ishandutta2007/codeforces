#include <bits/stdc++.h>

#define N 200005

using namespace std;

int i, j, m, n, p, k;

int f[N], deg[N], Q[N];

vector<int> v[N];

int bfs()
{
	Q[0] = 0;
	for (int i = 1; i <= n; ++i) if (deg[i] == 0) Q[++Q[0]] = i, f[i] = 1;
	for (int l = 1; l <= Q[0]; ++l)
	{
		int p = Q[l];
		for (int i = 0; i < (int)v[p].size(); ++i)
		{
			int k = v[p][i];
			--deg[k]; f[k] = max(f[k], f[p] + (k < p));
			if (!deg[k]) Q[++Q[0]] = k; 
		}
	}
	if (Q[0] != n) return -1;
	for (int i = 1; i <= n; ++i) f[1] = max(f[i], f[1]);
	return f[1];
}

void Main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) v[i].clear(), deg[i] = 0, f[i] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x, y; scanf("%d", &deg[i]);
		for (int j = 1; j <= deg[i]; ++j)
		{
			scanf("%d", &x);
			v[x].push_back(i);
		}
	}
	int ans = bfs();
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (;T--;) Main();
}