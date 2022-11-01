#include <iostream>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll ans = 0;
		ll current = 1;
		while (current < k) {
			current *= 2;
			++ans;
		}
		ans += (n - current + k - 1ll) / k;
		cout << ans << '\n';
	}
	return 0;
}