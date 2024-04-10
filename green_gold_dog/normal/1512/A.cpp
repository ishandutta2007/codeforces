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
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (ll i = 0; i < n; i++) {
			bool b = false;
			for (ll j = 0; j < n; j++) {
				b = b || (arr[i] == arr[j] && i != j);
			}
			if (!b) {
				cout << i + 1 << '\n';
			}
		}
	}
}
/*
















*/