#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n, s; cin >> n >> s;
	vector<int> a(n); for (int &x: a) cin >> x;
	sort(all(a));
	ll ans = abs(a[n / 2] - s);
	for (int i = 0; i < n / 2; ++i) {
		if (a[i] > s) ans += a[i] - s;
	}	
	for (int i = n / 2 + 1; i < n; ++i) {
		if (a[i] < s) ans += s - a[i];
	}
	cout << ans << "\n";
	return 0;
}