#include <algorithm>
#include <iostream>
#include <vector>
const int N = 2e5+1, MAX = 1e6, INF = 1e9+7;
int n, fen[N], a[N], res[N];
int comp[MAX + 1], inv[MAX + 1], next[MAX + 1];
typedef std::pair<int,int> TQuery;
#define _index first
#define _r second
std::vector<TQuery> query[N];

void sieve()
{
	for (int i = 2; i <= MAX; ++i)
		if (!comp[i])
			for (int j = 1; j <= MAX / i; ++j)
				comp[i * j] = i;
}

void set(int pos, int val)
{
	for (int i = pos; i <= n; i += i & -i)
		fen[i] = 1LL * fen[i] * val % INF;
}

int get(int pos)
{
	int res = 1;
	for (int i = pos; i >= 1; i -= i & -i)
		res = 1LL * res * fen[i] % INF;
	return res;
}

int main()
{
	sieve();
	inv[1] = 1;
	for (int i = 2; i <= MAX; ++i)
		inv[i] = INF - 1LL * INF / i * inv[INF % i] % INF;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		fen[i] = 1;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	int q; std::cin >> q;
	for (int i = 1; i <= q; ++i)
	{
		int l, r; std::cin >> l >> r;
		query[l].push_back(TQuery(i, r));
	}
	for (int i = n; i >= 1; --i)
	{
		set(i, a[i]);
		int tmp = a[i];
		while (tmp > 1)
		{
			int p = comp[tmp];
			while (tmp % p == 0)
				tmp /= p;
			if (next[p])
				set(next[p], 1LL * inv[p - 1] * p % INF);
			next[p] = i;
			set(i, 1LL * (p - 1) * inv[p] % INF);
		}
		for (TQuery q : query[i])
			res[q._index] = get(q._r);
	}
	for (int i = 1; i <= q; ++i)
		std::cout << res[i] << std::endl;
	return 0;
}