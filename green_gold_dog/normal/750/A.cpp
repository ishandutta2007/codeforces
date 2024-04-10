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
	ll n, k;
	cin >> n >> k;
	ll col = 240 - k;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		col -= i * 5;
		if (col < 0) {
			break;
		}
		ans++;
	}
	cout << ans;
}

/*
















*/