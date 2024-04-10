#include <algorithm>
#include <iostream>
#include <vector>
const int N = 2e5+1;
int n, p[N], pos[N], d[N], ti[N], to[N], h[N];
std::vector<int> adj[N], prv[N];
struct TNode
{
	int min, max;
	bool chk;
	int l, r;
};
TNode node[4 * N];

int time;
void dfs(int u)
{
	ti[u] = ++time;
	for (int v : adj[u])
	{
		h[v] = h[u] + 1;
		prv[v].push_back(u);
		while (prv[v].size() <= prv[prv[v].back()].size())
			prv[v].push_back(prv[prv[v].back()][prv[v].size() - 1]);
		dfs(v);
	}
	to[u] = ++time;
}

inline bool is_child(int u, int v) { return ti[u] >= ti[v] && to[u] <= to[v]; }
int lca(int u, int v)
{
	if (is_child(v, u))
		return u;
	for (int i = prv[u].size(); i >= 1; --i)
		if (i <= prv[u].size() && !is_child(v, prv[u][i - 1]))
			u = prv[u][i - 1];
	return prv[u].front();
}

struct compare_h { bool operator () (int lhs, int rhs) { return h[lhs] < h[rhs]; } };
inline int max_h(int lhs, int rhs) { return std::max(lhs, rhs, compare_h()); }
bool on_path(int mid, int l, int r) 
{
	if (mid == l)
		return true;
	if (mid == r)
		return true;
	if (is_child(l, mid) && is_child(mid, r))
		return true;
	if (is_child(r, mid) && is_child(mid, l))
		return true;
	return mid == max_h(lca(l, r), max_h(lca(l, mid), lca(mid, r)));
}

struct compare_ti { bool operator () (int lhs, int rhs) { return ti[lhs] < ti[rhs]; } };
inline int min_ti(int lhs, int rhs) { return std::min(lhs, rhs, compare_ti()); }
inline int max_ti(int lhs, int rhs) { return std::max(lhs, rhs, compare_ti()); }
struct compare_to { bool operator () (int lhs, int rhs) { return to[lhs] < to[rhs]; } };
inline int min_to(int lhs, int rhs) { return std::min(lhs, rhs, compare_to()); }
TNode merge(TNode lhs, TNode rhs)
{
	TNode res;
	res.min = lhs.min;
	res.max = rhs.max;
	res.chk = lhs.chk && rhs.chk;
	if (!res.chk)
		return res;
	res.l = min_to(min_to(lhs.l, lhs.r), min_to(rhs.l, rhs.r));
	res.r = max_ti(max_ti(lhs.l, lhs.r), max_ti(rhs.l, rhs.r));
	if (res.l == res.r)
		res.r = min_ti(min_ti(lhs.l, lhs.r), min_ti(rhs.l, rhs.r));
	else
		res.chk = on_path(lhs.l, res.l, res.r)
		       && on_path(lhs.r, res.l, res.r)
		       && on_path(rhs.l, res.l, res.r)
		       && on_path(rhs.r, res.l, res.r);
	return res;
}

void build_tree(int l, int r, int idx = 1)
{
	if (r - l == 1)
	{
		node[idx].min = l;
		node[idx].max = r;
		node[idx].chk = true;
		node[idx].l = node[idx].r = pos[l];
	}
	else 
	{
		int mid = (l + r) / 2;
		build_tree(l, mid, idx * 2);
		build_tree(mid, r, idx * 2 + 1);
		node[idx] = merge(node[idx * 2], node[idx * 2 + 1]);
	}
}

void update(int x)
{
	int idx = 1;
	while (node[idx].max - node[idx].min > 1)
	{
		idx *= 2;
		idx += node[idx].max <= x;
	}
	node[idx].l = node[idx].r = pos[x];
	while (idx > 1)
	{
		idx /= 2;
		node[idx] = merge(node[idx * 2], node[idx * 2 + 1]);
	}
}

int query()
{
	if (node[1].chk)
		return n;
	int idx = 1;
	while (!node[idx].chk)
		idx *= 2;
	TNode res = node[idx];
	++idx;
	while (node[idx].max - node[idx].min > 1)
	{
		idx *= 2;
		if (node[idx].chk)
		{
			TNode tmp = merge(res, node[idx]);
			if (tmp.chk)
			{
				++idx;
				res = tmp;
			}
		}
	}
	return res.max;
}

int main()
{
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> p[i];
		pos[p[i]] = i;
	}
	for (int i = 2; i <= n; ++i)
	{
		std::cin >> d[i];
		adj[d[i]].push_back(i);
	}
	dfs(1);
	build_tree(0, n);
	int q; std::cin >> q;
	for (int i = 1; i <= q; ++i)
	{
		int t; std::cin >> t;
		switch (t)
		{
		case 1:
		{
			int i, j; std::cin >> i >> j;
			std::swap(p[i], p[j]);
			std::swap(pos[p[i]], pos[p[j]]);
			update(p[i]);
			update(p[j]);
			break;
		}
		case 2:
			std::cout << query() << std::endl;
			break;
		}
	}
	return 0;
}