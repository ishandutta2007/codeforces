#include <iostream>
#include <vector>

#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int main() {
	ll n, k, l;
	cin >> n >> k >> l;
	vector <vector <pair <ll, ll>>> d(n + 1);
	for (ll i = 1; i <= n; i++)
		d[i].resize(n + k + 1);
	for (ll i = 1; i < l; i++)
		d[1][i].first = 1;
	for (ll i = l; i <= k; i++)
		d[1][i].second = 1;
	for (ll i = 1; i < n; i++)
		for (ll j = 1; j < n; j++) {
			for (ll y = 1; y < l; y++) {
				d[i + 1][j + y].first = (d[i + 1][j + y].first + d[i][j].first) % MOD;
				d[i + 1][j + y].second = (d[i + 1][j + y].second + d[i][j].second) % MOD;
			}
			for (ll y = l; y <= k; y++)
				d[i + 1][j + y].second = (d[i + 1][j + y].second + d[i][j].first + d[i][j].second) % MOD;
		}
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
		ans = (ans + d[i][n].second) % MOD;
	cout << ans;
	return 0;
}