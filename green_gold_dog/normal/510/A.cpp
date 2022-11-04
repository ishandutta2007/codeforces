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
	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (ll j = 0; j < m; j++) {
				cout << '#';
			}
			cout << '\n';
		} else {
			if ((i + 1) % 4 == 0) {
				cout << '#';
			}
			for (ll j = 0; j < m - 1; j++) {
				cout << '.';
			}
			if ((i + 1) % 4 == 2) {
				cout << '#';
			}
			cout << '\n';
		}
	}
}

/*
















*/