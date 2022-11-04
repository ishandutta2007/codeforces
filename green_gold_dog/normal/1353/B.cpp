#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n, 0), b(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (ll i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		ll ans = 0, u2 = k - 1;
		for (ll i = k; i > 0; i--) {
			ans += max(b[n - i], a[u2]);
			if (a[u2] > b[n - i]) {
				u2--;
			}
		}
		for (ll i = k; i < n; i++) {
			ans += a[i];
		}
		cout << ans << '\n';
	}
}
/*
















*/