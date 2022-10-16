#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n;
	vector<int> a(n); for (int &x: a) cin >> x;
	sort(all(a));
	vector<ll> pw(n + 1);
	pw[0] = 1;
	for (int i = 1; i < n + 1; ++i) {
		pw[i] = (pw[i - 1] * 2) % MOD;
	}
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		ans += ((pw[i] - 1) * a[i]) % MOD;
		if (ans >= MOD) ans -= MOD;
	}
	for (int i = 0; i + 1 < n; ++i) {
		ans -= ((pw[n - i - 1] - 1) * a[i]) % MOD;
		if (ans < 0) ans += MOD;
	}
	cout << ans << "\n";
	return 0;
}