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
		ll c1 = 0, c2 = 0;
		for (ll i = 0; i < n; i++) {
			ll a;
			cin >> a;
			if (i % 2 != a % 2) {
				if (i % 2 == 0) {
					c1++;
				} else {
					c2++;
				}
			}
		}
		cout << (c1 == c2 ? c1 : -1) << '\n';
	}
}
/*
















*/