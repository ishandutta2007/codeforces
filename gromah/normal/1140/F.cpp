#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
#define K 300000
#define N 300000 + 5
#define M 1048576 + 5
#define E 6000000 + 5
#define mp make_pair
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, sz, Fa[N << 1], Height[N << 1], X[N << 1], Y[N << 1], Head[M], Stack[N << 1][3];
LL cur, Ans[N];
map <Pii, int> Map;

struct Link
{
	int next, a, b;
}h[E];

inline void addedge(int x, int a, int b)
{
	static int tot = 0;
	h[++ tot].next = Head[x], Head[x] = tot;
	h[tot].a = a, h[tot].b = b;
}

void Add(int x, int l, int r, int s, int t, int a, int b)
{
	if (l == s && r == t)
	{
		addedge(x, a, b);
		return ;
	}
	int mid = l + r >> 1;
	if (t <= mid)
		Add(ls(x), l, mid, s, t, a, b);
	else if (s > mid)
		Add(rs(x), mid + 1, r, s, t, a, b);
	else Add(ls(x), l, mid, s, mid, a, b), Add(rs(x), mid + 1, r, mid + 1, t, a, b);
}

int Find(int x)
{
	for (; x != Fa[x]; x = Fa[x]) ;
	return x;
}

void dfs(int x, int l, int r)
{
	int _sz = sz;
	for (int i = Head[x]; i; i = h[i].next)
	{
		int a = h[i].a, b = h[i].b;
		int u = Find(a), v = Find(K + b);
		if (u == v) continue ;
		if (Height[u] > Height[v])
			swap(u, v);
		sz ++, Stack[sz][0] = u, Stack[sz][1] = v, Stack[sz][2] = Height[v];
		cur -= 1LL * X[u] * Y[u] + 1LL * X[v] * Y[v];
		Fa[u] = v, X[v] += X[u], Y[v] += Y[u], Height[v] = max(Height[v], Height[u] + 1);
		cur += 1LL * X[v] * Y[v];
	}
	if (l == r)
		Ans[l] = cur;
	else
	{
		int mid = l + r >> 1;
		dfs(ls(x), l, mid);
		dfs(rs(x), mid + 1, r);
	}
	for (; sz > _sz; sz --)
	{
		int u = Stack[sz][0], v = Stack[sz][1], height = Stack[sz][2];
		cur -= 1LL * X[v] * Y[v];
		Fa[u] = u, X[v] -= X[u], Y[v] -= Y[u], Height[v] = height;
		cur += 1LL * X[u] * Y[u] + 1LL * X[v] * Y[v];
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1, x, y; i <= n; i ++)
	{
		scanf("%d%d", &x, &y);
		int &t = Map[mp(x, y)];
		if (t)
		{
			Add(1, 1, n, t, i - 1, x, y);
			Map.erase(mp(x, y));
		}
		else t = i;
	}
	for (const pair<Pii, int> &p : Map)
	{
		int x = p.first.first, y = p.first.second, t = p.second;
		Add(1, 1, n, t, n, x, y);
	}
	for (int i = 1; i <= 2 * K; i ++)
		Fa[i] = i, Height[i] = 1, X[i] = (i <= K), Y[i] = (i > K);
	dfs(1, 1, n);
	for (int i = 1; i <= n; i ++)
		printf("%lld%c", Ans[i], i == n ? '\n' : ' ');
	return 0;
}