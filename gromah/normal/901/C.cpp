#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5
#define M 1048576 + 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, m, q, depth, cnt, Last[N], T[N], Low[N], L[N], R[N], Ord[N], Dfn[N], Stack[N], Del[M];
LL Tree[M], Ans[N];
bool Flag[N];
vector <int> Vec[N];

void dfs(int z, int last)
{
	Dfn[z] = Low[z] = ++ depth;
	Stack[++ Stack[0]] = z;
	Flag[z] = 1;
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == last) continue ;
		if (!Dfn[d])
			dfs(d, z), Low[z] = min(Low[z], Low[d]);
		else if (Flag[d])
			Low[z] = min(Low[z], Dfn[d]);
	}
	if (Dfn[z] == Low[z])
	{
		T[0] = 0;
		int j, Min = n, Max = 0;
		do
		{
			j = Stack[Stack[0] --];
			Min = min(Min, j);
			Max = max(Max, j);
			T[++ T[0]] = j;
		} while (j != z);
		if (Min != Max)
			Last[Max] = Min;
	}
}

bool cmp(int u, int v)
{
	return R[u] < R[v];
}

void apply(int x, int l, int r, int k)
{
	Tree[x] += 1LL * k * (r - l + 1);
	Del[x] += k;
}

void push(int x, int l, int r)
{
	if (Del[x])
	{
		int mid = l + r >> 1;
		apply(ls(x), l, mid, Del[x]);
		apply(rs(x), mid + 1, r, Del[x]);
		Del[x] = 0;
	}
}

void update(int x)
{
	Tree[x] = Tree[ls(x)] + Tree[rs(x)];
}

void Modify(int x, int l, int r, int s, int t)
{
	if (l == s && r == t)
	{
		apply(x, l, r, 1);
		return ;
	}
	push(x, l, r);
	int mid = l + r >> 1;
	if (t <= mid) Modify(ls(x), l, mid, s, t);
	else if (s > mid) Modify(rs(x), mid + 1, r, s, t);
	else Modify(ls(x), l, mid, s, mid), Modify(rs(x), mid + 1, r, mid + 1, t);
	update(x);
}

LL Query(int x, int l, int r, int s, int t)
{
	if (l == s && r == t) return Tree[x];
	push(x, l, r);
	int mid = l + r >> 1;
	if (t <= mid) return Query(ls(x), l, mid, s, t);
	else if (s > mid) return Query(rs(x), mid + 1, r, s, t);
	else return Query(ls(x), l, mid, s, mid) + Query(rs(x), mid + 1, r, mid + 1, t);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++)
		if (!Dfn[i])
			dfs(i, 0);
	for (int i = 1; i <= n; i ++)
		Last[i] = max(Last[i], Last[i - 1]);
	scanf("%d", &q);
	for (int i = 1, l, r; i <= q; i ++)
	{
		scanf("%d%d", &l, &r);
		L[i] = l, R[i] = r;
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + q + 1, cmp);
	for (int i = 1, t = 1; i <= n; i ++)
	{
		Modify(1, 1, n, Last[i] + 1, i);
		for (; t <= q && R[Ord[t]] == i; t ++)
			Ans[Ord[t]] = Query(1, 1, n, L[Ord[t]], R[Ord[t]]);
	}
	for (int i = 1; i <= q; i ++)
		printf("%lld\n", Ans[i]);
	return 0;
}