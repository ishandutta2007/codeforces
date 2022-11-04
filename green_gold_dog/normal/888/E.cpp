#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1000000000000000;

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

ll add(ll a, ll b, ll m) {
	if (a + b >= m) {
		return a + b - m;
	}
	return a + b;
}

ll sub(ll a, ll b, ll m) {
	if (a - b < 0) {
		return a - b + m;
	}
	return a - b;
}

ll mul(ll a, ll b, ll m) {
	return a * b % m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] = mul(arr[i], 1, m);
	}
	set<ll> all;
	ll mid = n / 2;
	ll mid2 = n - mid;
	for (ll i = 0; i < (1 << mid); i++) {
		ll now = 0;
		for (ll j = 0; j < mid; j++) {
			now = add(now, arr[j] * ((i >> j) & 1), m);
		}
		all.insert(-now);
	}
	ll ans = 0;
	for (ll i = 0; i < (1 << mid2); i++) {
		ll now = 0;
		for (ll j = 0; j < mid2; j++) {
			now = add(now, arr[j + mid] * ((i >> j) & 1), m);
		}
		assign_max(ans, now - (*all.upper_bound(-(m - now))));
	}
	cout << ans;
}