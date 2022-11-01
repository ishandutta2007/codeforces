#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll k;
		cin >> k;
		map <ll, ll> cnt;
		ll ans = 0;
		while (n--) {
			ll val;
			cin >> val;
			if (val % k) cnt[k - val % k]++;
		}
		for (auto &now : cnt) {
			ll m = now.first, x = now.second;
			x--;
			ans = max(ans, x * k + m);
		}
		if (ans) ans++;
		cout << ans << '\n';
	}
	return 0;
}