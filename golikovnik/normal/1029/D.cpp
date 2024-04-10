#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

using namespace __gnu_pbds;

cc_hash_table<int, int> rem[12];

int get_len(int x) {
	if (!x) return 0;
	return 1 + get_len(x / 10);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n, k; cin >> n >> k;
	vector<int> a(n);
	vector<int> lens(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		lens[i] = get_len(a[i]);
		++rem[lens[i]][a[i] % k];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		--rem[lens[i]][a[i] % k];
		int l = 1;
		for (ll pw = 10ll; l < 11; (pw *= 10) %= k, ++l) {
			ll cur = a[i] % k;
			cur *= pw;
			cur %= k;
			ans += rem[l][(k - cur) % k];
		}
		++rem[lens[i]][a[i] % k];
	}
	cout << ans << "\n";
	return 0;
}