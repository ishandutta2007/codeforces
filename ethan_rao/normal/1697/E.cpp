#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int inf = 1e9, p = 998244353;
struct Q
{
	int x, y;
	Q operator-(const Q &o) const { return {x - o.x, y - o.y}; }
	int len() const { return abs(x) + abs(y); }
};
Q a[100];
int dis[100];
vector<int> e[100];
bool ed[100], flg[100];
int f[101][100], c[101][101], fac[101];
int main()
{
	vector<int> sz;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, i, j, k, l, r = 1;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
	fill_n(dis, n, inf);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (int y = (a[i] - a[j]).len(); i != j && dis[i] > y)
			{
				dis[i] = y;
			}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if ((a[i] - a[j]).len() == dis[i])
				e[i].push_back(j);
	for (i = 0; i < n; i++)
		if (!ed[i])
		{
			auto &av = e[i];
			int m = av.size();
			for (j = 0; j < m; j++)
				if (dis[av[j]] != dis[i])
					break;
			if (j < m)
			{
				sz.push_back(1);
				continue;
			}
			else
			{
				flg[i] = 1;
				for (int x : av)
					flg[x] = 1;
				bool fg = 1;
				for (int y : av)
					for (int x : e[y])
						fg &= flg[x];
				for (j = 0; j < m; j++)
					for (k = j + 1; k < m; k++)
						fg &= (a[av[j]] - a[av[k]]).len() == dis[i];
				for (int x : av)
					flg[x] = 0;
				flg[i] = 0;
				if (!fg)
				{
					sz.push_back(1);
					continue;
				}
				sz.push_back(m + 1);
				for (int x : av)
					ed[x] = 1;
			}
		}
	// for (int x : sz)
	//	cerr << x << '\n';
	assert(accumulate(all(sz), 0) == n);
	int m = sz.size();
	fac[0] = 1;
	for (i = 1; i <= 100; i++)
		fac[i] = (ll)fac[i - 1] * i % p;
	for (i = 0; i <= 100; i++)
		c[i][0] = 1;
	for (i = 1; i <= 100; i++)
		for (j = 1; j <= i; j++)
			if ((c[i][j] = c[i - 1][j] + c[i - 1][j - 1]) >= p)
				c[i][j] -= p;
	f[0][0] = 1;
	for (i = 0; i < m; i++)
	{
		for (j = sz[i]; j <= n; j++)
			f[i + 1][j] = (f[i + 1][j] + (ll)f[i][j - sz[i]] * c[n - (j - sz[i])][sz[i]] % p * fac[sz[i]]) % p;
		if (sz[i] > 1)
			for (j = 1; j <= n; j++)
				f[i + 1][j] = (f[i + 1][j] + (ll)f[i][j - 1] * (n - (j - 1))) % p;
	}
	// for (i = 0; i <= m; i++)
	//	for (j = 0; j <= n; j++)
	//		if (f[i][j])
	//			cerr << i << ' ' << j << ' ' << f[i][j] << '\n';
	cout << accumulate(f[m], f[m] + n + 1, 0ll) % p << endl;
}