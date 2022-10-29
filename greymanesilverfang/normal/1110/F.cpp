#include <algorithm>
#include <iostream>
#include <vector>
#define mp std::make_pair
const int N = 5e5+1;
const long long INF = 1e15;
int l[N], r[N];
long long d[N], ans[N];
typedef std::pair<int,int> TEdge;
#define _node first
#define _weight second
std::vector<TEdge> adj[N];
typedef std::pair<int,std::pair<int,int>> TQuery;
#define _index first
#define _l second.first
#define _r second.second
std::vector<TQuery> query[N];

struct TSegtree 
{
	struct TNode
	{
		int l, r;
		long long ans, val;
	};
	TNode node[2000000];
	void build(int l, int r, int id = 1)
	{
		node[id].l = l;
		node[id].r = r;
		if (l == r)
		{
			node[id].ans = d[l];
			node[id].val = 0;
			return;
		}
		build(l, (l + r) / 2, id * 2);
		build((l + r) / 2 + 1, r, id * 2 + 1);
		node[id].ans = std::min(node[id * 2].ans, node[id * 2 + 1].ans);
		node[id].val = 0;
	}
	void update(int l, int r, int val, int id = 1)
	{
		if (r < node[id].l || node[id].r < l)
			return;
		if (l <= node[id].l && node[id].r <= r)
		{
			node[id].val += val;
			return;
		}
		update(l, r, val, id * 2);
		update(l, r, val, id * 2 + 1);
		node[id].ans = std::min(node[id * 2].ans + node[id * 2].val, node[id * 2 + 1].ans + node[id * 2 + 1].val);
	}
	long long query(int l, int r, int id = 1)
	{
		if (r < node[id].l || node[id].r < l)
			return INF;
		if (l <= node[id].l && node[id].r <= r)
			return node[id].ans + node[id].val;
		return std::min(query(l, r, id * 2), query(l, r, id * 2 + 1)) + node[id].val;
	}
	// void print(int id = 1)
	// {
		// std::cout << "node " << id << " " << node[id].l << " " << node[id].r << " " << node[id].ans << " " << node[id].val << std::endl;
		// if (node[id].l != node[id].r)
		// {
			// print(id * 2);
			// print(id * 2 + 1);
		// }
	// }
};
TSegtree tree;

void dfs(int u)
{
	// std::cout << "DFS " << u << std::endl;
	// tree.print();
	for (TQuery q : query[u])
		ans[q._index] = tree.query(q._l, q._r);
	for (TEdge e : adj[u])
	{
		tree.node[1].val += e._weight;
		tree.update(l[e._node], r[e._node], -e._weight * 2);
		dfs(e._node);
		tree.node[1].val -= e._weight;
		tree.update(l[e._node], r[e._node], e._weight * 2);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, q; std::cin >> n >> q;
	for (int i = 2; i <= n; ++i)
	{
		int p, w; std::cin >> p >> w;
		adj[p].push_back(mp(i, w));
	}
	for (int i = 1; i <= n; ++i)
		for (TEdge e : adj[i])
			d[e._node] = d[i] + e._weight;
	for (int i = n; i >= 1; --i)
		if (adj[i].empty())
			l[i] = r[i] = i;
		else 
		{
			l[i] = l[adj[i].front()._node];
			r[i] = r[adj[i].back()._node];
			d[i] = INF;
		}
	tree.build(1, n);
	for (int i = 1; i <= q; ++i)
	{
		int v, l, r; std::cin >> v >> l >> r;
		query[v].push_back(mp(i, mp(l, r)));
	}
	dfs(1);
	for (int i = 1; i <= q; ++i)
		std::cout << ans[i] << std::endl;
	return 0;
}