#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b)
{
	while (b)
	{
		ll c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, p;
		cin >> n >> p;
		vector<int> a(n), vis(n, 0);
		vector<pair<int, int> > v;
		for (int i = 0; i < n; i++) cin >> a[i], v.push_back({ a[i], i });
		sort(v.begin(), v.end());
		ll ans = 0;
		for (pair<int, int> pi : v)
		{
			int i = pi.second;
			if (a[i] >= p) break;
			ll g1 = a[i];
			for (int l = i - 1; l >= 0; l--)
			{
				g1 = gcd(a[l], g1);
				if (vis[l] || g1 != a[i]) break;
				vis[l] = 1; ans += a[i];
			}
			ll g2 = a[i];
			for (int r = i + 1; r < n; r++)
			{
				g2 = gcd(a[r], g2);
				if (vis[r - 1] || g2 != a[i]) break;
				vis[r - 1] = 1; ans += a[i];
			}
		}
		ans += p * 1ll * (n - 1 - count(vis.begin(), vis.end(), 1));
		cout << ans << "\n";
	}
	return 0;
}