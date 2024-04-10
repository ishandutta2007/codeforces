#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 6e5;
struct dat {
	int u, v;
} edge[N];
int prv[N];
bool chk[N];
std::vector<int> adj[N];
int in[N], ex[N], p[N], vis[N], mark[N], res[N], val[N];

int root(int u)
{
	return prv[u] ? prv[u] = root(prv[u]) : u;
}

bool merge(int u, int v)
{
	u = root(u);
	v = root(v);
	if (u == v)
		return false;
	prv[u] = v;
	return true;
}

int travel(int u, int e)
{
	return u ^ edge[e].u ^ edge[e].v;
}

void dfs(int u)
{
	static int time;
	in[u] = ++time;
	for (int e : adj[u])
		if (e != p[u])
		{
			int v = travel(u, e);
			p[v] = e;
			dfs(v);
		}
	ex[u] = ++time;
}

bool is_parent(int u, int v)
{
	return in[u] <= in[v] && ex[v] <= ex[u];
}

bool check(std::vector<int> &cycle)
{
	static int time;
	std::sort(cycle.begin(), cycle.end());
	for (int i = 0; i < cycle.size(); ++i)
	{
		int u = edge[cycle[i]].u;
		int v = edge[cycle[i]].v;
		if (i == 0)
			++time;
		else if (vis[u] < time && vis[v] < time)
			return false;
		vis[u] = vis[v] = time;
	}
	return true;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		edge[i] = {u, v};
		if (merge(u, v))
		{
			chk[i] = true;
			adj[u].push_back(i);
			adj[v].push_back(i);
		}
	}
	dfs(1);
	for (int i = 1; i <= m; ++i)
		if (!chk[i])
		{
			int u = edge[i].u;
			int v = edge[i].v;
			std::vector<int> cycle;
			while (!is_parent(u, v))
			{
				cycle.push_back(p[u]);
				u = travel(u, p[u]);
			}
			while (!is_parent(v, u))
			{
				cycle.push_back(p[v]);
				v = travel(v, p[v]);
			}
			if (check(cycle))
				mark[cycle[0]] = i;
		}
	for (int i = 1; i <= n; ++i)
		res[i] = 1;
	for (int i = m; i >= 1; --i)
	{
		int u = edge[i].u;
		int v = edge[i].v;
		val[i] = res[u] = res[v] = res[u] + res[v] - val[mark[i]];
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i] - 1);
	puts("");
}