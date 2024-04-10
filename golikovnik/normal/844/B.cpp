#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}	
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			cnt += a[i][j];
		}
		ans += (1LL << cnt) - 1;
		ans += (1LL << (m - cnt)) - 1;
	}
	for (int j = 0; j < m; ++j) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += a[i][j];
		}
		ans += (1LL << cnt) - 1;
		ans += (1LL << (n - cnt)) - 1;
		ans -= (ll)n;
	}
	cout << ans;
	return 0;
}