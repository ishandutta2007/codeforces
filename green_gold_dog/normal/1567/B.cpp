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
	vector<ll> arr(1000000, 0);
	for (ll i = 1; i < 1000000; i++) {
		arr[i] = arr[i - 1] ^ i;
	}
	for (ll _ = 0; _ < t; _++) {
		ll a, b;
		cin >> a >> b;
		ll ans = arr[a - 1];
		if (ans == b) {
			cout << a << '\n';
		} else {
			if ((ans ^ b) == a) {
				cout << a + 2 << '\n';
			} else {
				cout << a + 1 << '\n';
			}
		}
	}
}

/*
















*/