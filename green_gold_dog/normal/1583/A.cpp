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
		vector<ll> arr(n, 0);
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		bool b = true;
		for (ll i = 2; i * i <= sum; i++) {
			if (sum % i == 0) {
				b = false;
				break;
			}
		}
		bool b2 = false, b4 = false;
		cout << n - b << '\n';
		for (ll i = 0; i < n; i++) {
			if (!b || ((b2 || (arr[i] % 2 == 0)))) {
				cout << i + 1 << ' ';
			}
			if (arr[i] % 2 == 1) {
				b2 = true;
			}
		}
		cout << '\n';
	}
}

/*
















*/