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
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(n, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += arr[n / 2][i];
		ans += arr[i][n / 2];
		ans += arr[i][i];
		ans += arr[i][n - i - 1];
	}
	ans -= arr[n / 2][n / 2] * 3;
	cout << ans;
}
/*
















*/