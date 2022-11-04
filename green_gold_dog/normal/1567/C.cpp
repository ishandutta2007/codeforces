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
		string n;
		cin >> n;
		ll ans = 0;
		for (ll i = 0; i < (1 << n.size()); i++) {
			ll na = 1;
			bool b = true;
			for (ll j = 0; j < n.size(); j++) {
				if (((n[j] - '0' - 1 + (j > 1 && (i >> (j - 2) & 1)) < 0) || j == n.size() - 1 || j == n.size() - 2) && (i >> j & 1)) {
					na = 0;
					b = false;
					break;
				} else {
					ll nn = n[j] - '0' - (i >> j & 1);
					if (j > 1 && (i >> (j - 2) & 1)) {
						na *= 9 - nn;
						b = b & (nn % 2 == 0);
					} else {
						na *= nn + 1;
						b = b & (nn % 2 == 0);
					}
				}
			}
			ans += na;
		}
		cout << ans - 2 << '\n';
	}
}

/*
















*/