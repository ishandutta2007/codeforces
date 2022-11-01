#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;

const ll MOD = 1e9 + 7;
const int MAXK = 2e6;

ll binp(ll a, ll p) {
	if (p == 0) return 1;
	if (p % 2) return a * binp(a, p - 1) % MOD;
	ll x = binp(a, p / 2);
	return x * x % MOD;
}

ll var2 = 0;

bool can(map <int, ll> &cnt, ll p, int it, ll need) {
	if (it < 0) return false;
	if (need > 1e6) return false;
	if (cnt[it] >= need) {
		cnt[it] -= need;
		return true;
	}
	var2 += binp(p, it) * cnt[it];
	var2 %= MOD;
	need -= cnt[it];
	cnt[it] = 0;
	bool ans = can(cnt, p, it - 1, need * p);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll p;
		cin >> n >> p;
		vector <ll> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (p == 1) {
			if (n % 2) cout << 1 << '\n';
			else cout << 0 << '\n';
			continue;
		}
		map <int, ll> cnt;
		for (int i = 0; i < n; i++)
			cnt[a[i]]++;
		ll var1 = 0;
		var2 = 0;
		for (auto it = --cnt.end();; it--) {
			int c = it->first, pow = it->second;
			if (it->second % 2) {
				it->second = 0;
				if (can(cnt, p, c - 1, p)) {
					var2 = 0;
					continue;
				}
				var1 = binp(p, c);
				break;
			}
			it->second = 0;
			if (it == cnt.begin()) break;
		}
		if (cnt.empty()) {
			cout << 0 << '\n';
			continue;
		}
		for (auto &now : cnt) {
			var2 += (binp(p, now.first) * now.second % MOD);
			var2 %= MOD;
		}
		cout << ((var1 - var2) % MOD + MOD) % MOD << '\n';
	}
	return 0;
}