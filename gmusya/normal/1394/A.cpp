#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, d, m;
	cin >> n >> d >> m;
	vector <ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] <= m)
			cnt++;
	vector <ll> pre(n);
	pre[0] = a[0];
	for (int i = 1; i < n; i++)
		pre[i] = pre[i - 1] + a[i];
	ll ans = 0;
	for (int i = 0; i <= cnt; i++) {
		ll s = 0;
		s += (cnt - 1 >= 0 ? pre[cnt - 1] : 0) - (cnt - i - 1 >= 0 ? pre[cnt - i - 1] : 0);
		ll x = (n - i + d) / (d + 1);
		{
			int t1 = 0, t2 = 0;
			t1 = min(x, (ll) n - cnt);
			t2 = x - t1;
			s += pre[n - 1] - (n - t1 - 1 >= 0 ? pre[n - t1 - 1] : 0);
			s += (cnt - i - 1 >= 0 ? pre[cnt - i - 1] : 0) - (cnt - i - t2 - 1 >= 0 ? pre[cnt - i - t2 - 1] : 0);
		}
		ans = max(ans, s);
	}
	cout << ans;
	return 0;
}