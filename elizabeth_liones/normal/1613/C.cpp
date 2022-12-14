#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n; ll h;
		cin >> n >> h;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<ll> d;
		for (int i = 0; i + 1 < n; i++) d.push_back(a[i + 1] - a[i]);
		d.push_back(h);
		sort(d.begin(), d.end());
		ll ans = 1e18;
		for (int i = 0; i < n; i++)
		{
			ll lf = n - i;
			ll k = (h + lf - 1) / lf;
			if (i) k = max(k, d[i - 1]);
			if (k <= d[i])
			{
				ans = min(ans, k);
			}
			h -= d[i];
		}
		cout << ans << "\n";
	}
	return 0;
}