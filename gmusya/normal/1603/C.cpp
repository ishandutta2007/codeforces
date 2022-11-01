#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<pair<int, ll>> cnt;
		ll ans = 0;
		ll sum = 0;
		for (int l = n - 1; l >= 0; --l) {
			vector<pair<int, ll>> new_cnt;
			int al = a[l];
			new_cnt.reserve(cnt.size() + 1);
			for (auto& now : cnt) {
				int value = now.first;
				int terms = (al - 1 + value) / value;
				sum += now.second * 1ll * (terms - 1);
				new_cnt.emplace_back(al / terms, now.second);
			}
			sum %= MOD;
			ans += sum;
			new_cnt.emplace_back(al, 1);
			cnt.clear();
			sort(new_cnt.begin(), new_cnt.end());
			int last = -1;
			ll val = 0;
			for (auto& now : new_cnt) {
				if (last != now.first) {
					if (val) {
						cnt.emplace_back(last, val);
					}
					val = 0;
					last = now.first;
				}
				val += now.second;
			}
			cnt.emplace_back(last, val);
		}
		cout << ans % MOD << '\n';
	}
	return 0;
}