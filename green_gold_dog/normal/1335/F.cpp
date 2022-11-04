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
		ll n, m;
		cin >> n >> m;
		vector<vector<pair<ll, ll>>> arr(n, vector<pair<ll, ll>>(m)), new_arr(n, vector<pair<ll, ll>>(m));
		vector<vector<ll>> color(n, vector<ll>(m, 0));
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				char c;
				cin >> c;
				color[i][j] = c - '0';
			}
		}
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				char c;
				cin >> c;
				if (c == 'U') {
					arr[i][j] = {i - 1, j};
				}
				if (c == 'R') {
					arr[i][j] = {i, j + 1};
				}
				if (c == 'D') {
					arr[i][j] = {i + 1, j};
				}
				if (c == 'L') {
					arr[i][j] = {i, j - 1};
				}
			}
		}
		for (ll k = 0; k < 20; k++) {
			for (ll i = 0; i < n; i++) {
				for (ll j = 0; j < m; j++) {
					new_arr[i][j] = arr[arr[i][j].first][arr[i][j].second];
				}
			}
			arr = new_arr;
		}
		map<pair<ll, ll>, ll> ans;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				if (color[i][j] == 0 || ans.count(arr[i][j]) == 0) {
					ans[arr[i][j]] = color[i][j];
				}
			}
		}
		ll a1 = 0, a2 = 0;
		for (auto[__, i] : ans) {
			a1++;
			a2 += i == 0;
		}
		cout << a1 << ' ' << a2 << '\n';
	}
}

/*
















*/