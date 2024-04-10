#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

const ll MOD = 1e8;

int main() {
	ll n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	vector <vector <vector <pair <int, int>>>> d(n1 + n2 + 1);
	for (ll i = 0; i <= n1 + n2; i++) {
		d[i].resize(n1 + 2);
		for (ll j = 0; j <= n1 + 1; j++)
			d[i][j].resize(max(k1, k2) + 2);
	}
	d[1][1][1].first = 1;
	d[1][0][1].second = 1;
	for (ll i = 1; i < n1 + n2; i++) {
		for (ll j = 0; j <= n1; j++) {
			for (ll y = 0; y <= max(k1, k2); y++) {
				if (y < k1)
					d[i + 1][j + 1][y + 1].first = (d[i + 1][j + 1][y + 1].first + d[i][j][y].first) % MOD;
				d[i + 1][j][1].second = (d[i + 1][j][1].second + d[i][j][y].first) % MOD;
				if (y < k2)
					d[i + 1][j][y + 1].second = (d[i + 1][j][y + 1].second + d[i][j][y].second) % MOD;
				d[i + 1][j + 1][1].first = (d[i + 1][j + 1][1].first + d[i][j][y].second) % MOD;
			}
		}
	}
	ll ans = 0;
	for (ll y = 0; y <= max(k1, k2); y++) 
		ans = (ans + d[n1 + n2][n1][y].first + d[n1 + n2][n1][y].second) % MOD;
	cout << ans;
	return 0;
}