#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll bin(ll x, ll p) {
	if (!p) {
		return 1;
	}
	if (p & 1) {
		return bin(x, p - 1) * x % MOD;
	} else {
		ll t = bin(x, p / 2);
		return t * t % MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		ll ans = 1;
		for (int i = n - 1; i >= n - k; i -= 1) {
			if (a[i] != 0 && a[i] != -1) {
				ans = 0;
				break;
			}
			ans = ans * (n - i) % MOD;
		}
		for (int i = 0; i < n - k; ++i) {
			if (a[i] == -1) {
				ans = ans * (i + k + 1) % MOD;
			} else if (a[i] == 0) {
				ans = ans * (k + 1) % MOD;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}