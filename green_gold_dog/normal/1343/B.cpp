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
		if (n % 4 == 0) {
			cout << "YES\n";
			for (ll i = 1; i <= n / 2; i++) {
				cout << i * 2 << ' ';
			}
			for (ll i = 1; i < n / 2; i++) {
				cout << i * 2 - 1 << ' ';
			}
			cout << n - 1 + n / 2 << '\n';
		} else {
			cout << "NO\n";
		}
	}
}

/*
















*/