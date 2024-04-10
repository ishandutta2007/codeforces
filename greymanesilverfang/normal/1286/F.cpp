#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
const int N = 20;
int n, f[1<<N], g[(int)log2(N)+1][N+1][1<<N], tmp[2][N+1][1<<N];
long long a[N];

bool check(int mask, int sz)
{
	if (sz < 2)
		return false;
	long long sum = 0;
	int cnt = 0;
	std::vector<long long> l(1), r(1);
	for (int i = 0; i < n; ++i)
	{
		if (mask >> i & 1 ^ 1)
			continue;
		sum += a[i];
		if (cnt++ == sz / 2)
			std::swap(l, r);
		for (int j = l.size(); j > 0; --j)
		{
			l.push_back(l[j - 1] + a[i]);
			l[j - 1] -= a[i];
		}
	}
	if (sum & 1 ^ sz & 1 ^ 1)
		return false;
	std::sort(r.begin(), r.end());
	for (long long x : l)
	{
		auto it1 = std::lower_bound(r.begin(), r.end(), -x - sz);
		auto it2 = std::lower_bound(r.begin(), r.end(), -x + sz);
		if (it1 != it2)
		{
			if ((x != l.front() || x + *it1 != -sum || std::next(it1) != it2) &&
			    (x != l.back()  || x + *it1 !=  sum || std::next(it1) != it2))
				return true;
		}
	}
	return false;
}

void inv_zeta(const int p, const int a[N+1][1<<N], int b[1<<N])
{
	for (int i = p * 2; i <= n; ++i)
		std::copy(a[i], a[i] + (1 << n), tmp[0][i]);
	int cur = 0, prv = 1;
	for (int i = 0; i < n; ++i)
	{
		std::swap(cur, prv);
		for (int j = p * 2; j <= n; ++j)
			for (int k = 0; k < 1 << n; ++k)
				tmp[cur][j][k] = k & 1 << i ? tmp[prv][j][k] - tmp[prv][j][k ^ 1 << i] : tmp[prv][j][k];
	}
	for (int i = 0; i < 1 << n; ++i)
		if (__builtin_popcount(i) >= p * 2)
			b[i] = std::min(tmp[cur][__builtin_popcount(i)][i], 1);
}

bool zeta(const int p, const int a[1<<N], int b[N+1][1<<N])
{
	bool flag = false;
	for (int i = p * 2; i <= n; ++i)
		std::fill(tmp[0][i], tmp[0][i] + (1 << n), 0);
	for (int i = 0; i < 1 << n; ++i)
		if (__builtin_popcount(i) >= p * 2 && a[i] == 1)
		{
			flag = true;
			tmp[0][__builtin_popcount(i)][i] = 1;
		}
	if (!flag)
		return false;
	int cur = 0, prv = 1;
	for (int i = 0; i < n; ++i)
	{
		std::swap(cur, prv);
		for (int j = p * 2; j <= n; ++j)
			for (int k = 0; k < 1 << n; ++k)
				tmp[cur][j][k] = k & 1 << i ? tmp[prv][j][k] + tmp[prv][j][k ^ 1 << i] : tmp[prv][j][k];
	}
	for (int i = p * 2; i <= n; ++i)
		std::copy(tmp[cur][i], tmp[cur][i] + (1 << n), b[i]);
	return true;
}

bool or_convo(const int p, const int a[N+1][1<<N], const int q, const int b[N+1][1<<N], int c[N+1][1<<N])
{
	for (int i = (p + q) * 2; i <= n; ++i)
		std::fill(c[i], c[i] + (1 << n), 0);
	for (int i = p * 2; i <= n - q * 2; ++i)
		for (int j = q * 2; j <= n - i; ++j)
			for (int k = 0; k < 1 << n; ++k)
				c[i + j][k] += a[i][k] * b[j][k];
	inv_zeta(p + q, c, f);
	return zeta(p + q, f, c);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; ++i)
		while (a[i] == 0 && i < n)
			std::swap(a[i], a[--n]);
	for (int i = 0; i < 1 << n; ++i)
		if (check(i, __builtin_popcount(i)))
			f[i] = 1;
	if (!zeta(1, f, g[0]))
	{
		printf("%d\n", n);
		return 0;
	}
	int cur = 0;
	while (or_convo(1 << cur, g[cur], 1 << cur, g[cur], g[cur + 1]))
		++cur;
	int res = 1 << cur, prv = cur, nxt = cur + 1;
	while (prv--)
		if (or_convo(1 << prv, g[prv], res, g[cur], g[nxt]))
		{
			std::swap(cur, nxt);
			res += 1 << prv;
		}
	printf("%d\n", n - res);
}