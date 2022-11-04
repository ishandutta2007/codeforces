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

void solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> ans(n + 1, 0);
	for (ll i = 0; i < n; i++) {
		vector<ll> pref(n + 1, 0);
		for (ll j = i; j < n; j++) {
			pref[j + 1] = pref[j] + arr[j];
		}
		vector<ll> suff_max(n + 1, 0);
		suff_max[n] = pref[n];
		for (ll j = n - 1; j >= 0; j--) {
			suff_max[j] = max(suff_max[j + 1], pref[j]);
		}
		ll now = suff_max[i];
		assign_max(ans[0], now);
		for (ll j = i + 1; j <= n; j++) {
			assign_max(now, suff_max[j] + x * (j - i));
			assign_max(ans[j - i], now);
		}
		for (ll j = n + 1; j <= n + i; j++) {
			assign_max(ans[j - i], now);
		}
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
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