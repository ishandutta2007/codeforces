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
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < i; j++) {
				cout << "()";
			}
			ll cnt = n - i;
			for (ll j = 0; j < cnt; j++) {
				cout << '(';
			}
			for (ll j = 0; j < cnt; j++) {
				cout << ')';
			}
			cout << '\n';
		}
	}
}

/*
















*/