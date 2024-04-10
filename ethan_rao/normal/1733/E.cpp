#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const ll mod = 1'000'000'007;
int testcases;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> testcases;
	for (int I = 1; I <= testcases; I++)
	{
		ll t;
		int n, m;
		cin >> t >> n >> m;
		function<ll(ll, int, int)> dp = [&](ll t, int n, int m)
		{
			if (t < 0)
			{
				return 0ll;
			}
			vector f(n + 2, vector(m + 2, 0ll));
			f[0][0] = t;
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= m; j++)
				{
					f[i + 1][j] += f[i][j] / 2;
					f[i][j + 1] += (f[i][j] + 1) / 2;
				}
			}
			return f[n][m];
		};
		if (dp(t + 1 - n - m, n, m) != dp(t - n - m, n, m))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}