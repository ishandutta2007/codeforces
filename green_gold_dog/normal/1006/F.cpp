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
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = 0;
	vector<vector<ll>> a(n, vector<ll>(m, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	ll mid1 = (n + m - 2) / 2;
	ll mid2 = n + m - 2 - mid1;
	vector<map<ll, ll>> arr(mid1 + 1);
	for (ll i = 0; i < (1 << mid1); i++) {
		ll now = 0, nx = 0, ny = 0;
		bool b = false;
		for (ll j = 0; j < mid1; j++) {
			if ((i >> j) & 1) {
				if (nx == n || ny == m) {
					b = true;
					break;
				}
				now ^= a[nx][ny];
				nx++;
			} else {
				if (ny == m || nx == n) {
					b = true;
					break;
				}
				now ^= a[nx][ny];
				ny++;
			}
		}
		if (b) {
			continue;
		}
		if (arr[nx].count(now) == 0) {
			arr[nx][now] = 0;
		}
		arr[nx][now]++;
	}
	for (ll i = 0; i < (1 << mid2); i++) {
		ll now = 0, nx = n - 1, ny = m - 1;
		bool b = false;
		for (ll j = 0; j < mid2; j++) {
			if ((i >> j) & 1) {
				nx--;
			} else {
				ny--;
			}
		}
		if (nx < 0 || ny < 0) {
			continue;
		}
		ll col = nx;
		now = a[nx][ny];
		for (ll j = 0; j < mid2; j++) {
			if ((i >> j) & 1) {
				nx++;
			} else {
				ny++;
			}
			now ^= a[nx][ny];
		}
		if (arr[col].count(k ^ now) != 0) {
			ans += arr[col][k ^ now];
		}
	}
	cout << ans;

}

/*
















*/