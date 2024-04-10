#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll k;
		cin >> k;
		set<ll> s;
		for (int i = 0; i < n; ++i) {
			ll x;
			cin >> x;
			s.insert(x);
		}
		bool can = false;
		for (ll x : s) {
			if (s.find(x + k) != s.end()) {
				can = true;
			}
		}
		if (can) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}