#include <cstdio>
#include <cmath>
#include <algorithm>
const int N = 90, M = 3e5;
const long long INF = 1e12;
long long f[N][M];

struct antenna 
{
	int x, s;
	bool operator < (const antenna &other) const 
	{
		return x < other.x;
	}
} a[N];

void mini(long long &x, long long y)
{
	if (x > y)
		x = y;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		int x, s; scanf("%d%d", &x, &s);
		a[i] = {x, s};
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= 2 * m; ++i)
		f[0][i] = INF;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 2 * m; ++j)
		{
			f[i][j] = f[i - 1][j];
			if (a[i].x < j)
				mini(f[i][j], f[i - 1][std::max(2 * a[i].x - j - 1, 0)] + std::max(j - a[i].x - a[i].s, 0));
		}
		for (int j = 2 * m; j >= 1; --j)
			mini(f[i][j - 1], f[i][j]);
	}
	printf("%lld", f[n][m]);
}