#include <iostream>
#include <vector>

#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int main() {
	ll n, k;
	cin >> n >> k;
	vector <vector <ll>> a(k + 1);
	for (ll i = 0; i <= k; i++)
		a[i].resize(n + 1);
	a[0][1] = 1;
	for (ll i = 0; i < k; i++)
		for (ll j = 1; j <= n; j++)
			for (ll z = 1; z * j <= n; z++)
				a[i + 1][z * j] = (a[i + 1][z * j] + a[i][j]) % MOD;
	ll ans = 0;
	for (ll j = 1; j <= n; j++)
		ans = (ans + a[k][j]) % MOD;
	cout << ans;
	return 0;
}