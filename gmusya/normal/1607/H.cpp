#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll> a(n), b(n), m(n);
		for (ll i = 0; i < n; ++i) {
			cin >> a[i] >> b[i] >> m[i];
		}
		map<ll, vector<ll>> decomposition;
		for (ll i = 0; i < n; ++i) {
			decomposition[a[i] + b[i] - m[i]].push_back(i);
		}
		ll answer = n;
		vector<ll> x(n);
		for (auto& now : decomposition) {
			sort(now.second.begin(), now.second.end(), [&](ll i, ll j) {
				return a[i] > a[j];
			});
			ll mi = a[now.second[0]] - m[now.second[0]];
			ll last = 0;
			for (ll i = 1; i < now.second.size(); ++i) {
				ll ind = now.second[i];
				if (a[ind] < mi) {
					for (ll j = last; j < i; ++j) {
						x[now.second[j]] = mi;
					}
					mi = a[ind] - m[ind];
					last = i;
				} else {
					--answer;
				}
				mi = max(mi, a[ind] - m[ind]);
			}
			for (ll j = last; j < now.second.size(); ++j) {
				x[now.second[j]] = mi;
			}
		}
		cout << answer << '\n';
		for (ll i = 0; i < n; ++i) {
			ll res_left = max(x[i], 0ll);
			ll res_right = a[i] + b[i] - m[i] - res_left;
			if (res_right < 0) {
				res_left += res_right;
				res_right = 0;
			}
			cout << a[i] - res_left << ' ' << b[i] - res_right << '\n';
		}
	}
	return 0;
}