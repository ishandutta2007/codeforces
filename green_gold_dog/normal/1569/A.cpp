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
		string s;
		cin >> s;
		bool b = true;
		for (ll i = 0; i < n - 1; i++) {
			if (s[i] != s[i + 1]) {
				cout << i + 1 << ' ' << i + 2 << '\n';
				b = !b;
				break;
			}
		}
		if (b) {
			cout << -1 << ' ' << -1 << '\n';
		}
	}
}

/*
















*/