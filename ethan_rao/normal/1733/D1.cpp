#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
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
		}
		cout << ans << '\n';
	}
}