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
	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	vector<int> pref(n + 1);
	partial_sum(all(a), pref.begin() + 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			int s = pref[j] - pref[i - 1];
			int len = j - i + 1;
			if (s > len * 100) {
				ans = max(ans, len);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}