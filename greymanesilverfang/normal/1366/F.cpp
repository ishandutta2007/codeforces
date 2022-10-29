#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
const int INF = 1e9+7, INV = 5e8+4, N = 2001;
int n, m, q;
struct Edge {
	int u, v, w;
	bool operator < (const Edge &other) const {
		return w < other.w;
	}
	bool operator > (const Edge &other) const {
		return w > other.w;
	}
} e[N];
std::vector<Edge> adj[N];
struct Func {
	int a, b; // y = ax - b;
	bool operator < (const Func &other) const {
		if (a != other.a)
			return a < other.a;
		return b < other.b;
	}
};
std::vector<Func> fv;

int dis[N];
bool mini(int &x, int y)
{
	return x > y ? x = y, true : false;
}
void dijkstra(Edge loop)
{
	std::fill(dis + 1, dis + N, INF);
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> heap;
	heap.push({0, 1, 0});
	while (!heap.empty())
	{
		Edge edge = heap.top();
		heap.pop();
		if (!mini(dis[edge.v], edge.w))
			continue;
		for (Edge next : adj[edge.v])
			if (next.w < loop.w)
				heap.push({next.u, next.v, dis[edge.v] + loop.w - next.w});
	}
	if (dis[loop.u] > dis[loop.v])
		std::swap(loop.u, loop.v);
	if (dis[loop.u] < INF)
		fv.push_back({loop.w, dis[loop.u]});
}

int cut(Func f1, Func f2)
{
	return (f1.b - f2.b) / (f1.a - f2.a);
}

int mod(long long x)
{
	return (x %= INF) < 0 ? x + INF : x;
}

int mul(int x, int y)
{
	return mod(1LL * mod(x) * mod(y));
}

int calc(Func f, int x1, int x2)
{
	return mul(mul(mul(f.a, x1 + x2 + 1) - 2 * f.b, x2 - x1), INV);
}

int main() 
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i)
	{
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		e[i] = {u, v, w};
		adj[u].push_back({u, v, w});
		adj[v].push_back({v, u, w});
	}
	for (int i = 0; i < m; ++i)
		dijkstra(e[i]);
	std::sort(fv.begin(), fv.end());
	std::vector<Func> hull;
	std::vector<int> point;
	for (Func f : fv)
	{
		while (!hull.empty())
		{
			if (f.a == hull.back().a)
				break;
			long long x = cut(f, hull.back());
			if (x > q)
				break;
			if (x > point.back())
			{
				hull.push_back(f);
				point.push_back(x);
				break;
			}
			hull.pop_back();
			point.pop_back();
		}
		if (hull.empty())
		{
			hull.push_back(f);
			point.push_back(0);
		}
	}
	point.push_back(q);
	for (int i = 0; i < hull.size(); ++i)
	{
		// printf("func: y = %dx - %d\n", hull[i].a, hull[i].b);
		// printf("start: %d\n", point[i]);
	}
	long long res = 0;
	for (int i = 0; i < hull.size(); ++i)
		res += calc(hull[i], point[i], point[i + 1]);
	printf("%d", mod(res));
	return 0;
}