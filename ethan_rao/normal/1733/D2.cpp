#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const ll INF = 9'000'000'000'000'000'000;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n;
		ll x, y;
		string s, t;
		cin >> n >> x >> y >> s >> t;
		for (int i = 0; i < n; i++)
		{
			s[i] ^= t[i];
		}
		n = 0;
		for (auto c : s)
		{
			if (c)
			{
				++n;
			}
		}
		ll ans = -1;
		if (y <= x)
		{
			if (n % 2 == 0)
			{
				if ((n == 2) && (s.find(1) + 1 == s.rfind(1)))
				{
					ans = min(2 * y, x);
				}
				else
				{
					ans = y * n / 2;
				}
			}
		}
		else
		{
			if (n % 2 == 0)
			{
				vector<int> a(n + 1);
				vector<ll> f(n + 2), g(n + 2);
				n = 0;
				for (int i = 0; i < s.size(); i++)
				{
					if (s[i])
					{
						a[n++] = i;
					}
				}
				f[0] = 0;
				g[0] = INF;
				f[1] = INF;
				g[1] = INF;
				for (int i = 0; i < n; i++)
				{
					ll tmp = (a[i + 1] - a[i]) * x;
					f[i + 2] = f[i] + tmp;
					g[i + 2] = g[i] + tmp;
					f[i + 1] = min(f[i + 1], g[i] + y / 2);
					g[i + 1] = min(g[i + 1], f[i] + (y + 1) / 2);
				}
				ans = f[n];
			}
		}
		cout << ans << '\n';
	}
}