#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

ll sum(ll n) {
	return n * (n + 1) / 2;
}

int main() {
	int n;
	cin >> n;
	ll x;
	cin >> x;
	vector <ll> a(n + n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	vector <ll> cnt_days(n + n);
	vector <ll> cnt_val(n + n);
	cnt_days[0] = a[0];
	cnt_val[0] = sum(a[0]);
	for (int i = 1; i < n + n; i++) {
		cnt_days[i] = cnt_days[i - 1] + a[i];
		cnt_val[i] = cnt_val[i - 1] + sum(a[i]);
	}
	ll ans = 0;
	for (int i = n; i < n + n; i++) {
		int it = upper_bound(cnt_days.begin(), cnt_days.end(), cnt_days[i] - x) - cnt_days.begin();
		ll tmp = cnt_val[i] - cnt_val[it];
		ll d = x - (cnt_days[i] - cnt_days[it]);
		tmp += (a[it] + a[it] - d + 1) * d / 2;
		ans = max(ans, tmp);
	}
	cout << ans << '\n';
	return 0;
}