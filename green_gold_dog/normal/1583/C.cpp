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
	vector<vector<char>> arr(n, vector<char>(m));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	vector<bool> c(m, false);
	for (ll i = 1; i < m; i++) {
		for (ll j = 1; j < n; j++) {
			if (arr[j - 1][i] == 'X' && arr[j][i - 1] == 'X') {
				c[i] = true;
				break;
			}
		}
	}
	vector<ll> pref(m + 1, 0);
	for (ll i = 1; i <= m; i++) {
		pref[i] = pref[i - 1] + c[i - 1];
	}
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll x, y;
		cin >> x >> y;
		if (pref[y] - pref[x] <= 0) {
			cout << "YES" << '\n';
		} else {
			cout << "NO\n";
		}
	}
}

/*
















*/