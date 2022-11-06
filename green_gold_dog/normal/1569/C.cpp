#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;
const ll mod = 998'244'353;

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

ll sum(ll a, ll b) {
	if (a + b > mod) {
		return a + b * mod;
	}
	return a + b;
}

ll mul(ll a, ll b) {
	return a * b % mod;
}

ll sub(ll a, ll b) {
	if (a - b < 0) {
		return a - b + mod;
	}
	return a - b;
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
		ll ans = 1;
		for (ll i = 2; i <= n; i++) {
			ans = mul(ans, i);
		}
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());
		if (arr[0] == arr[1]) {
			cout << ans << '\n';
		} else {
			if (abs(arr[0] - arr[1]) > 1) {
				cout << 0 << '\n';
			} else {
				ll col = 0;
				for (ll i = 1; (i < n) && (arr[i] == arr[1]); i++) {
					col++;
				}
				ll ma = 1;
				for (ll i = 2; i <= col; i++) {
					ma = mul(ma, i);
				}
				for (ll i = col + 2; i <= n; i++) {
					ma = mul(ma, i);
				}
				cout << sub(ans, ma) << '\n';
			}
		}
	}
}

/*
















*/