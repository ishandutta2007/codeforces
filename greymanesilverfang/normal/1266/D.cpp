#include <cstdio>
#include <vector>
const int N = 2e5;
long long val[N];
struct dat {
	int id; long long val;
};
struct edge {
	int u, v; long long w;
};

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int u, v, d; scanf("%d%d%d", &u, &v, &d);
		val[u] += d;
		val[v] -= d;
	}
	std::vector<edge> res;
	std::vector<dat> pos, neg;
	for (int u = 1; u <= n; ++u)
	{
		if (val[u] > 0)
			pos.push_back({u, val[u]});
		if (val[u] < 0)
			neg.push_back({u, -val[u]});
		while (!pos.empty() && !neg.empty())
		{
			int u = pos.back().id;
			int v = neg.back().id;
			long long w = std::min(pos.back().val, neg.back().val);
			res.push_back({u, v, w});
			if (!(pos.back().val -= w))
				pos.pop_back();
			if (!(neg.back().val -= w))
				neg.pop_back();
		}
	}
	printf("%d\n", res.size());
	for (edge e : res)
		printf("%d %d %lld\n", e.u, e.v, e.w);
}