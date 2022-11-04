#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		vector<ll> arr_1, arr_2;
		for (ll i = 0; i < n; i++) {
			ll x;
			cin >> x;
			if (x % 2 == 0) {
				arr_1.push_back(i);
			} else {
				arr_2.push_back(i);
			}
		}
		if (abs((ll)arr_1.size() - (ll)arr_2.size()) > 1) {
			cout << -1 << '\n';
		} else {
			ll ans = INF;
			if (arr_1.size() <= arr_2.size()) {
				ll a = 0;
				for (ll i = 0; i < n; i++) {
					if (i % 2 == 0) {
						a += abs(arr_2[i / 2] - i);
					} else {
						a += abs(arr_1[i / 2] - i);
					}
				}
				ans = min(ans, a / 2);
			}
			if (arr_1.size() >= arr_2.size()) {
				ll a = 0;
				for (ll i = 0; i < n; i++) {
					if (i % 2 == 0) {
						a += abs(arr_1[i / 2] - i);
					} else {
						a += abs(arr_2[i / 2] - i);
					}
				}
				ans = min(ans, a / 2);
			}
			cout << ans << '\n';
		}
	}
}

/*
















*/