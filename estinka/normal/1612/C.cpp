#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
typedef long long ll;
using namespace std;

ll tri(ll x)
{
	return x * (x + 1) / 2ll;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll k, x;
		cin >> k >> x;
		if (tri(k) + tri(k - 1) <= x)
		{
			cout << 2 * k - 1 << "\n";
		}
		else if (tri(k) < x)
		{
			// najdeme poslednu spravu, ktoru este mozeme napisat a nedostaneme ban
			x -= tri(k);
			ll lo = 0, hi = k - 1;
			while (lo < hi)
			{
				ll m = (lo + hi + 1) / 2;
				if (tri(k - 1) - tri(k - 1 - m) < x) lo = m;
				else hi = m - 1;
			}
			cout << k + lo + 1 << "\n";
		}
		else
		{
			// najdeme poslednu spravu, ktoru este mozeme napisat a nedostaneme ban
			ll lo = 0, hi = k;
			while (lo < hi)
			{
				ll m = (lo + hi + 1) / 2;
				if (tri(m) < x) lo = m;
				else hi = m - 1;
			}
			cout << lo + 1 << "\n";
		}
	}
	return 0;
}