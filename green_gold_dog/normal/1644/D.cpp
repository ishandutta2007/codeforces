#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000, MOD = 998'244'353;

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

void solve() {
	ll n, m, k, q;
	cin >> n >> m >> k >> q;
	ll ans = 1;
	vector<pair<ll, ll>> arr(q);
	for (ll i = 0; i < q; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	set<ll> nc, mc;
	reverse(arr.begin(), arr.end());
	for (auto[a, b] : arr) {
		if (nc.size() == n) {
			break;
		}
		if (mc.size() == m) {
			break;
		}
		if ((nc.find(a) == nc.end()) || (mc.find(b) == mc.end())) {
			ans *= k;
			ans %= MOD;
		}
		nc.insert(a);
		mc.insert(b);
	}
	cout << ans << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
/*
















*/