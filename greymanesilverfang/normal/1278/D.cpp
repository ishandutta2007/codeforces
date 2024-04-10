#include <cstdio>
#include <algorithm>
#include <set>
const int N = 6e5;
int n;
struct edge {
	int l, r;
	bool operator < (const edge &other) const {
		return l < other.l;
	}
} seg[N];
struct point {
	int pos, id;
	bool operator < (const point &other) const {
		return pos < other.pos;
	}
};
int cnt = 0;
int prv[N];

int root(int u)
{
	return prv[u] == -1 ? u : prv[u] = root(prv[u]);
}

bool merge(int u, int v)
{
	u = root(u);
	v = root(v);
	if (u == v)
		return false;
	prv[u] = v;
	++cnt;
	return true;
}

bool solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int l, r; scanf("%d%d", &l, &r);
		seg[i] = {l, r};
	}
	std::sort(seg, seg + n);
	std::set<point> r;
	std::fill(prv, prv + N, -1);
	for (int i = 0; i < n; ++i)
	{
		point dl = {seg[i].l, i};
		point dr = {seg[i].r, i};
		for (auto it = r.lower_bound(dl); it != r.end() && *it < dr; ++it)
			if (!merge(i, it->id))
				return false;
		r.insert(dr);
	}
	return cnt == n - 1;
}

int main()
{
	printf("%s\n", solve() ? "YES" : "NO");
}