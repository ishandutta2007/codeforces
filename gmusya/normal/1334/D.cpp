#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n, l, r;
		cin >> n >> l >> r;
		l--, r--;
		ll pos = 0;
		ll x = 2 * (n - 1);
		ll level = 1;
		vector <int> ans;
		while (pos < n * (n - 1)) {
			ll L = pos;
			ll R = pos + x - 1;
			L = max(l, L);
			R = min(r, R);
			for (ll i = L; i <= R; i++) {
				ll val = i - pos;
				if (i % 2 == 0) ans.push_back(level);
				else ans.push_back(level + (val + 1) / 2);
			}
			pos += x;
			x -= 2;
			level++;
		}
		if (r == n * (n - 1)) ans.push_back(1);
		for (auto &now : ans)
			cout << now << ' ';
		cout << '\n';
	}
	return 0;
}