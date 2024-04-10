#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const int N = 200'010;
int a[N], mn[N], prime[N], id[N], w[N], step[N];
ll f[50][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	for (int i = 2; i <= 200'000; i++)
	{
		if (mn[i] == 0)
		{
			prime[++cnt] = i;
			mn[i] = i;
		}
		for (int j = 1; (j <= cnt) && (i * prime[j] <= 200'000); j++)
		{
			mn[i * prime[j]] = prime[j];
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n, q;
		cin >> n >> q;
		int m = 0;
		for (int x = n; x > 1;)
		{
			int y = mn[x];
			w[++m] = y;
			step[m] = n / y;
			id[y] = m;
			while (x % y == 0)
			{
				x /= y;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < step[i]; j++)
			{
				f[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			for (int j = 1; j <= m; j++)
			{
				f[j][i % step[j]] += a[i];
			}
		}
		multiset<ll> s;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < step[i]; j++)
			{
				s.insert(f[i][j] * step[i]);
			}
		}
		cout << *s.rbegin() << '\n';
		cout.flush();
		while (q--)
		{
			int p, x;
			cin >> p >> x;
			for (int i = 1; i <= m; i++)
			{
				s.erase(s.find(f[i][p % step[i]] * step[i]));
				f[i][p % step[i]] += x - a[p];
				s.insert(f[i][p % step[i]] * step[i]);
			}
			a[p] = x;
			cout << *s.rbegin() << '\n';
		}
	}
}