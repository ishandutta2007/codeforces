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
		cout << (n / 10000 != 0) + (n / 1000 % 10 != 0) + (n / 100 % 10 != 0) + (n / 10 % 10 != 0) + (n % 10 != 0) << ' ';
		if (n / 10000 != 0) {
			cout << n / 10000 * 10000 << ' ';
		}
		if (n / 1000 % 10 != 0) {
			cout << n / 1000 % 10 * 1000 << ' ';
		}
		if (n / 100 % 10 != 0) {
			cout << n / 100 % 10 * 100 << ' ';
		}
		if (n / 10 % 10 != 0) {
			cout << n / 10 % 10 * 10 << ' ';
		}
		if (n % 10 != 0) {
			cout << n % 10 << ' ';
		}
		cout << '\n';
	}
}

/*
















*/