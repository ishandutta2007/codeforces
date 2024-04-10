#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
typedef long long ll;
using namespace std;

ll divi(ll a, ll b)
{
	if (a % b != 0) return a / b - ((a ^ b) < 0);
	return a / b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		ll k;
		cin >> n >> k;
		ll sum = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
		sort(a.begin(), a.end());
		sum -= a[0];
		ll ans = 1e18, cnt = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			ll val = divi(k - sum, cnt);
			ans = min(ans, max(a[0] - val, 0ll) + cnt - 1);
			cnt++;
			sum -= a[i];
		}
		//cout << "			";
		cout << ans << "\n";
	}
	return 0;
}