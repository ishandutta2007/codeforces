#include <cstdio>
const int N = 3e5;
int par[N], size[N], chk[N];

int scc(int u)
{
	if (!par[u])
		return u;
	return par[u] = scc(par[u]);
}

bool connect(int u, int v)
{
	u = scc(u);
	v = scc(v);
	if (u == v)
		return false;
	par[u] = v;
	return true;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	int old_count = n;
	for (int i = 0; i < m; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		if (connect(u, v))
			--old_count;
	}
	for (int u = 1; u <= n; ++u)
		++size[scc(u)];
	int wait = 0;
	int new_count = 1;
	for (int u = 1; u <= n; ++u)
	{
		if (chk[scc(u)] < new_count)
		{
			wait += size[scc(u)];
			chk[scc(u)] = new_count;
		}
		if (!--wait)
			++new_count;
	}
	--new_count;
	printf("%d", old_count - new_count);
}