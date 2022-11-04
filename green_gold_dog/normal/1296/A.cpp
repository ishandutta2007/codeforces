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
		bool b = false, b2 = false;
		for (ll i = 0; i < n; i++) {
			ll a;
			cin >> a;
			b = b || (a % 2 == 0);
			b2 = b2 || (a % 2 == 1);
		}
		cout << (b2 && (b || (n % 2 == 1)) ? "YES" : "NO") << '\n';
	}
}
/*
















*/