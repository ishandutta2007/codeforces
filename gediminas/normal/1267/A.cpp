/*input
2
5 7 1
1 9 2

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll ans = 0;
	multiset<pair<pair<ll, ll>, ll>>A;
	multiset<pair<pair<ll, ll>, ll>>AT;
	multiset<pair<ll, ll>>BT;
	multiset<pair<ll, ll>>TB;
	while (n--)
	{
		ll a, b, t;
		cin >> a >> b >> t;
		A.insert({{a, b}, t});
		AT.insert({{a + t, b}, t});
	}
	ll l = 0;
	while (true)
	{
		ll nxt = 2e18;
		if (!A.empty())
		{
			if (A.begin()->first.first <= l)
			{
				ll a = A.begin()->first.first;
				ll b = A.begin()->first.second;
				ll t = A.begin()->second;
				A.erase(A.begin());
				AT.erase(AT.find({{a + t, b}, t}));
				BT.insert({b, t});
				TB.insert({t, b});
				continue;
			}
			else
				nxt = min(nxt, A.begin()->first.first);
		}
		if (!BT.empty())
		{
			if (BT.begin()->first <= l)
			{
				ll b = BT.begin()->first;
				ll t = BT.begin()->second;
				BT.erase({b, t});
				TB.erase({t, b});
				continue;
			}
			else
				nxt = min(nxt, BT.begin()->first);
		}
		if (!TB.empty())
		{
			ll t = TB.begin()->first;
			ll b = TB.begin()->second;
			ll dabar = l + t;
			nxt = min(nxt, b);
			if (l + t <= b)
			{
				if (!AT.empty())
				{
					if (AT.begin()->first.first < dabar)
					{
						ll at = AT.begin()->first.first;
						ll b = AT.begin()->first.second;
						ll t = AT.begin()->second;
						ll a = at - t;
						A.erase(A.find({{a, b}, t}));
						AT.erase(AT.begin());
						BT.insert({b, t});
						TB.insert({t, b});
						l = a;
						continue;
					}
				}
				ll k = max(1ll, (nxt - l) / t);
				l += t * k;
				ans += k;
			}
			else
			{
				TB.erase(TB.begin());
				BT.erase(BT.find({b, t}));
			}
			continue;
		}
		if (!A.empty())
		{
			if (A.begin()->first.first > l)
			{
				l = A.begin()->first.first;
				continue;
			}
		}
		break;
	}
	cout << ans << "\n";
}