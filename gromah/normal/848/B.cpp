#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define mp make_pair

int n, w, h, X[N], Y[N];

struct Node
{
	int x, y, ord, id;
	Node (int _x = 0, int _y = 0, int _ord = 0, int _id = 0)
	{
		x = _x, y = _y, ord = _ord, id = _id;
	}
	bool operator < (const Node& a) const
	{
		return mp(ord, x - y) < mp(a.ord, a.x - a.y);
	}
}P[N], E[N];

int main()
{
	scanf("%d%d%d", &n, &w, &h);
	for (int i = 1, g, p, t; i <= n; i ++)
	{
		scanf("%d%d%d", &g, &p, &t);
		P[i] = g == 1 ? Node(p, 0, p - t, i) : Node(0, p, p - t, i);
		E[i] = g == 1 ? Node(p, h, p - t, i) : Node(w, p, p - t, i);
	}
	sort(P + 1, P + n + 1);
	sort(E + 1, E + n + 1);
	for (int i = 1; i <= n; i ++)
	{
		int u = P[i].id;
		X[u] = E[i].x, Y[u] = E[i].y;
	}
	for (int i = 1; i <= n; i ++)
		printf("%d %d\n", X[i], Y[i]);
	return 0;
}