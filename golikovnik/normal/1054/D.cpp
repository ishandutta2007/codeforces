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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	auto inv = [&](int x) {
		return (1 << k) - x - 1;
	};
	ll ans = 0;
	map<int, int> cur;
	++cur[0];
	int cur_pref = 0;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		int y = inv(a[i]);
		if (i + 1 - cur[cur_pref ^ y] > i + 1 - cur[cur_pref ^ x]) {
			ans += (i + 1 - cur[cur_pref ^ y]);
			cur_pref ^= y;
		} else {
			ans += (i + 1 - cur[cur_pref ^ x]);
			cur_pref ^= x;
		}
		++cur[cur_pref];
	}	
	cout << ans << "\n";
	return 0;
}