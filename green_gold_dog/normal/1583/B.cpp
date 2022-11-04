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
		vector<bool> arr(n, false);
		ll m;
		cin >> m;
		for (ll i = 0; i < m; i++) {
			ll __, b;
			cin >> __ >> b >> __;
			b--;
			arr[b] = true;
		}
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			if (!arr[i]) {
				ans = i;
				break;
			}
		}
		for (ll i = 0; i < n; i++) {
			if (i != ans) {
				cout << i + 1 << ' ' << ans + 1 << '\n';
			}
		}
	}
}

/*
















*/