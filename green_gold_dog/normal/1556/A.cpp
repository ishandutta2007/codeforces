#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll c, d;
		cin >> c >> d;
		if (abs(c - d) % 2 == 1) {
			cout << -1 << '\n';
		} else {
			if (c == d) {
				if (c == 0) {
					cout << 0 << '\n';
				} else {
					cout << 1 << '\n';
				}
			} else {
				cout << 2 << '\n';
			}
		}
	}
}

/*
















*/