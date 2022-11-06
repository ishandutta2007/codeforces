#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define M 10000000 + 5
#define INF 1234567890

int n, root, tot, id, q, last, Dep[N], A[N], Ord[N], Root[N], L[N], R[N];
vector <int> Vec[N];

struct Segment_Tree
{
	int l, r, Min;
}h[M];

int New(int x)
{
	h[++ tot] = h[x];
	return tot;
}

void dfs(int z, int fa)
{
	L[z] = ++ id;
	Ord[z] = z;
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == fa) continue ;
		Dep[d] = Dep[z] + 1;
		dfs(d, z);
	}
	R[z] = id;
}

void update(int x)
{
	h[x].Min = min(h[h[x].l].Min, h[h[x].r].Min);
}

void Modify(int &x, int l, int r, int t, int k)
{
	x = New(x);
	if (l == r)
	{
		h[x].Min = min(h[x].Min, k);
		return ;
	}
	int mid = l + r >> 1;
	if (t <= mid) Modify(h[x].l, l, mid, t, k);
	else Modify(h[x].r, mid + 1, r, t, k);
	update(x);
}

int Query(int x, int l, int r, int s, int t)
{
	if ((l == s && r == t) || !x) return h[x].Min;
	int mid = l + r >> 1;
	if (t <= mid) return Query(h[x].l, l, mid, s, t);
	else if (s > mid) return Query(h[x].r, mid + 1, r, s, t);
	else return min(Query(h[x].l, l, mid, s, mid), Query(h[x].r, mid + 1, r, mid + 1, t));
}

int main()
{
	scanf("%d%d", &n, &root);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	dfs(root, h[0].Min = INF);
	sort(Ord + 1, Ord + n + 1, [&] (int u, int v) {return Dep[u] < Dep[v];});
	for (int d = 0, t = 1; d < n; d ++)
		for (Root[d] = d ? Root[d - 1] : 0; t <= n && Dep[Ord[t]] <= d; t ++)
			Modify(Root[Dep[Ord[t]]], 1, n, L[Ord[t]], A[Ord[t]]);
	for (scanf("%d", &q); q; q --)
	{
		int u, v, x, k, ans;
		scanf("%d%d", &u, &v);
		x = (u + last) % n + 1, k = (v + last) % n;
		last = ans = Query(Root[min(Dep[x] + k, n - 1)], 1, n, L[x], R[x]);
		printf("%d\n", ans);
	}
	return 0;
}