#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll pow10[19];

void init() {
	pow10[0] = 1;
	for (int i = 1; i <= 18; ++i) {
		pow10[i] = pow10[i - 1] * 10;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		++k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		ll ans = 0;
		for (int i = 0; i + 1 < n; ++i) {
			if (k < pow10[a[i + 1] - a[i]]) {
				ans += pow10[a[i]] * k;
				k = 0;
				break;
			} else {
				ans += (pow10[a[i + 1] - a[i]] - 1) * pow10[a[i]];
				k -= pow10[a[i + 1] - a[i]] - 1;
			}
		}
		if (k) {
			ans += k * pow10[a.back()];
		}
		cout << ans << endl;
	}
	return 0;
}