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

template<typename T>
T square(T& a) {
	return a * a;
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
		bitset<200> dp;
		dp[0] = 1;
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			ll a;
			cin >> a;
			sum += a;
			dp |= dp << a;
		}
		cout << ((sum % 2 == 0 && dp[sum / 2]) ? "YES" : "NO") << '\n';
	}
}
/*
















*/