/*input
3
2
0 1 0 0 0 0 0
100000000
1 0 0 0 1 0 1
1
1 0 0 0 0 0 0
*/
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
		ll k;
		cin >> k;
		ll x[7];
		for (ll i = 0; i < 7; i++)
			cin >> x[i];
		ll ans = k * 7;
		for (ll a = 0; a < 7; a++)
		{
			for (ll b = a; b < 7; b++)
			{
				ll suma = 0;
				for (ll i = a; i <= b; i++)
					suma += x[i];
				if (suma >= k)
					ans = min(ans, b - a + 1);
			}
		}
		ll suma = 0;
		for (ll i = 0; i < 7; i++)
			suma += x[i];
		for (ll a = 0; a < 7; a++)
		{
			for (ll b = 0; b < 7; b++)
			{
				ll kiek = 0;
				ll dien = 0;
				for (ll i = a; i < 7; i++)
				{
					dien += x[i];
					kiek++;
				}
				for (ll i = 0; i <= b; i++)
				{
					dien += x[i];
					kiek++;
				}
				if (dien < k)
				{
					ll m = abs((k - dien) / suma);
					dien += suma * m;
					kiek += 7 * m;
				}
				while (dien < k)
				{
					kiek += 7;
					dien += suma;
				}
				ans = min(ans, kiek);
			}
		}

		cout << ans << "\n";
	}
}