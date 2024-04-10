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
	for (ll i = 0; i < t; i++) {
		ll h, w, n;
		cin >> h >> w >> n;
		ll ans = 1;
		while (h % 2 == 0) {
			ans *= 2;
			h /= 2;
		}
		while (w % 2 == 0) {
			ans *= 2;
			w /= 2;
		}
		cout << (n <= ans ? "YES" : "NO") << '\n';
	}
}
/*
















*/