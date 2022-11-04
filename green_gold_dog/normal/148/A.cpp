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
	ll k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	ll ans = 0;
	for (ll i = 0; i < d; i++) {
	  ans += (i + 1) % k == 0 || (i + 1) % l == 0 || (i + 1) % m == 0 || (i + 1) % n == 0;
	}
	cout << ans;
}

/*
















*/