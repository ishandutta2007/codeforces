#include <iostream>
#include <vector>
#include <math.h>

#define ll long long

using namespace std;

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector <ll> a(n), b(m);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < m; i++)
		cin >> b[i];
	vector <ll> prefa(n + 1), prefb(m + 1);
	for (ll i = 1; i <= n; i++) 
		prefa[i] = a[i - 1] + prefa[i - 1];
	for (ll i = 1; i <= m; i++)
		prefb[i] = b[i - 1] + prefb[i - 1];
	ll ans = 0;
	for (ll i = 1; i <= ceil(sqrt(k)); i++) {
		if (k % i)
			continue;
		ll x = i;
		ll y = k / i;
		if (y < x)
			break;
		ll cnt1 = 0, cnt2 = 0;
		for (ll j = 1; j <= n - x + 1; j++)
			cnt1 += (prefa[j + x - 1] - prefa[j - 1] == x);
		for (int j = 1; j <= m - y + 1; j++) 
			cnt2 += (prefb[j + y - 1] - prefb[j - 1] == y);
		ans += cnt1 * cnt2;
		if (i * i == k)
			break;
		swap(x, y);
		cnt1 = cnt2 = 0;
		for (ll j = 1; j <= n - x + 1; j++)
			cnt1 += (prefa[j + x - 1] - prefa[j - 1] == x);
		for (int j = 1; j <= m - y + 1; j++)
			cnt2 += (prefb[j + y - 1] - prefb[j - 1] == y);
		ans += cnt1 * cnt2;
	}
	cout << ans;
	return 0;
}