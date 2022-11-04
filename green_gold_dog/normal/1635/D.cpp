#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, p;
	cin >> n >> p;
	set<ll> s;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		s.insert(x);
	}
	vector<ll> dp(p + 1, 0);
	for (auto i : s) {
		ll x = i;
		bool b = true;
		while (x > 0) {
			if (x % 4 == 0) {
				x /= 4;
			} else {
				if (x % 2 == 1) {
					x /= 2;
				} else {
					break;
				}
			}
			if (s.find(x) != s.end()) {
				b = false;
				break;
			}
		}
		if (b) {
			ll col = 0;
			while (i > 0) {
				i /= 2;
				col++;
			}
			if (col <= p) {
				dp[col]++;
			}
		}
	}
	ll mod = 1'000'000'007;
	ll ans = dp[1];
	for (ll i = 2; i <= p; i++) {
		dp[i] += dp[i - 1] + dp[i - 2];
		dp[i] %= mod;
		ans += dp[i];
		ans %= mod;
	}
	cout << ans;
}
/*
















*/