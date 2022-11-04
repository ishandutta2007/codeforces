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
		ll n;
		cin >> n;
		ll mina = INF, minb = INF;
		vector<pair<ll, ll>> arr(n, {0, 0});
		for (ll i = 0; i < n; i++) {
			cin >> arr[i].first;
			assign_min(mina, arr[i].first);
		}
		for (ll i = 0; i < n; i++) {
			cin >> arr[i].second;
			assign_min(minb, arr[i].second);
		}
		ll ans = 0;
		for (auto[a, b] : arr) {
			ans += max(a - mina, b - minb);
		}
		cout << ans << '\n';
	}
}
/*
















*/