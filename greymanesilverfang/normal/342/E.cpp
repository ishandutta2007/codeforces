#include <algorithm>
#include <iostream>
#include <vector>
const int N = 1e5+1;
bool chk[N];
int sz[N], h[N], res[N];
std::vector<int> adj[N];
struct TQuery {
	int index, node, type;
	TQuery() {}
	TQuery(int x, int y, int z) : index(x), node(y), type(z) {}
	bool operator < (const TQuery& other) const {
		return index < other.index;
	}
};
std::vector<TQuery> que[N], queries;

void dfs_cnt(int u, int p = 0)
{
	sz[u] = que[u].size() + 1;
	for (int v : adj[u])
	{
		if (chk[v])
			continue;
		if (v == p)
			continue;
		dfs_cnt(v, u);
		sz[u] += sz[v];
	}
}

void dfs_que(int u, int p = 0)
{
	for (TQuery q : que[u])
		queries.push_back(q);
	for (int v : adj[u])
	{
		if (chk[v])
			continue;
		if (v == p)
			continue;
		h[v] = h[u] + 1;
		dfs_que(v, u);
	}
}

void sub_solve(int u)
{
	queries.clear();
	h[u] = 0; 
	dfs_que(u);
	std::sort(queries.begin(), queries.end());
	int min_height = N;
	for (TQuery q : queries)
		if (q.type == 1)
			min_height = std::min(min_height, h[q.node]);
		else
			res[q.index] = std::min(res[q.index], h[q.node] + min_height);
}

void decomp(int u)
{
	dfs_cnt(u);
	int size = sz[u];
	bool is_centroid = false;
	while (!is_centroid)
	{
		is_centroid = true;
		for (int v : adj[u])
		{
			if (chk[v])
				continue;
			if (sz[u] < sz[v])
				continue;
			if (size / 2 < sz[v])
			{
				is_centroid = false;
				u = v;
				break;
			}
		}
	}
	chk[u] = true;
	sub_solve(u);
	for (int v : adj[u])
	{
		if (chk[v])
			continue;
		decomp(v);
	}
}

int main()
{
	int n, m; std::cin >> n >> m;
	for (int i = 1; i < n; ++i)
	{
		int a, b; std::cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	que[1].push_back(TQuery(0, 1, 1));
	for (int i = 1; i <= m; ++i)
	{
		int t, v; std::cin >> t >> v;
		que[v].push_back(TQuery(i, v, t));
	}
	std::fill(res + 1, res + m + 1, N);
	decomp(1);
	for (int i = 1; i <= m; ++i)
	{
		if (res[i] == N)
			continue;
		std::cout << res[i] << std::endl;
	}
	return 0;
}