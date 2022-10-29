// #fenwick_tree

#include <algorithm>
#include <cmath>
#include <cstdio>
const int N = 200001, Q = 50001, M = 500;
int n, m, q, l[Q], r[Q], a[N], fen[N][M];
long long res[Q];                                    // n^2 cannot be expressed by (int), but who knows if it can get there...

void add(int _x, int _y)
{
	for (int x = _x; x <= n; x += x & -x)
		for (int y = _y; y <= m; y += y & -y)
			++fen[x][y];
}

void del(int _x, int _y)
{
	for (int x = _x; x <= n; x += x & -x)
		for (int y = _y; y <= m; y += y & -y)
			--fen[x][y];
}

int get(int _x, int _y)
{
	int res = 0;
	for (int x = _x; x >= 1; x -= x & -x)
		for (int y = _y; y >= 1; y -= y & -y)
			res += fen[x][y];
	return res;
}

int get(int x1, int x2, int y1, int y2)
{
	return get(x1 - 1, y1 - 1) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x2, y2);
}

int query(int l, int r)
{
	if (l == r)
		return 0;  // this might or might not cause problems, but just to be sure...
	int res = 0;
	if (a[l] != 0)
	{
		res += get(l, r - 1, a[l] + 1, m) - get(l + 1, r, 1, a[l] - 1);
		del(l, a[l]);
		add(r, a[l]);
	}
	if (a[r] != 0)
	{
		res += get(l + 1, r, 1, a[r] - 1) - get(l, r - 1, a[r] + 1, m);
		del(r, a[r]);
		add(l, a[r]);
	}
	return res;
}

void solve(int lim)
{
	m = lim;
	for (int i = 1; i <= n; ++i)
		if (a[i] != 0)
			add(i, a[i]);
	for (int i = 1; i <= q; ++i)
	{
		res[i] += query(l[i], r[i]);
		std::swap(a[l[i]], a[r[i]]);
	}
	for (int i = 1; i <= n; ++i)
		if (a[i] != 0)
			del(i, a[i]);
}

int main()
{
	scanf("%d%d", &n, &q);
	int m = sqrt(n);
	for (int i = 1; i <= q; ++i)
	{
		scanf("%d%d", &l[i], &r[i]);
		if (l[i] >= r[i])
			std::swap(l[i], r[i]);
	}
	for (int i = 1; i <= n; ++i)
		a[i] = (i - 1) / m + 1;
	solve(n / m + 1);                  // note the limit here
	for (int i = 0; i <= n / m; ++i)
	{
		for (int i = 1; i <= n; ++i)
			a[i] = 0;
		for (int j = 1; j <= m; ++j)
			if (m * i + j <= n)        // caution: without this fen[][] can be accidentally overwritten 
				a[m * i + j] = j;
		solve(m);
	}
	for (int i = 1; i <= q; ++i)
		printf("%lld\n", res[i] += res[i - 1]);
	return 0;
}