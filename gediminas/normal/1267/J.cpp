/*input
3
11
1 5 1 5 1 5 1 1 1 1 5
6
1 2 2 2 2 1
5
4 3 3 1 2

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<ll>k(n + 3, 0);
		vector<ll>ans(n + 2, 0);
		vector<bool>ok(n + 2, true);
		vector<ll>M(n + 3, -1);
		for (ll i = 0; i < n; i++)
		{
			ll c;
			cin >> c;
			k[c - 1]++;
		}
		ll mn = n + 1;
		for (ll i = 0; i < n; i++)
		{
			if (k[i] == 0)
				continue;
			mn = min(mn, k[i] + 1);
			for (ll s = 1; s <= mn; s++)
			{
				ll mnn = n + 10;
				ll ab = k[i] / s;
				for (ll abb = ab - 2; abb <= ab + 2; abb++)
				{
					ll a = s * abb - k[i];
					if (0 <= a && a <= abb)
						mnn = min(mnn, abb);
				}
				if (mnn > n + 5)
				{
					ok[s] = false;
				}
				else
				{
					ans[s] += mnn;
				}
			}
		}
		ll r = n;
		for (ll i = 1; i <= mn; i++)
			if (ok[i])
				r = min(r, ans[i]);
		cout << r << "\n";
	}
}