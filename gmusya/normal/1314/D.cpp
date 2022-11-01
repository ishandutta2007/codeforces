#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime> 

#define ll long long

using namespace std;

const ll INF = 10e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vector <vector <ll>> a(n + 1, vector <ll>(n + 1));
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++) 
			cin >> a[i][j];
	for (ll i = 1; i <= n; i++)
		a[i][i] = INF;
	ll z = 500;
	ll ans = INF;	
	vector <ll> color(n + 1);
	while ((double) clock() / CLOCKS_PER_SEC < 2.8) {
		vector <vector <ll>> dp(k + 1, vector <ll>(n + 1, INF));
		for (ll i = 1; i <= n; i++)
			color[i] = rand() % 2;
		dp[0][1] = 0;
		for (ll i = 0; i < k; i++)
			for (ll j = 1; j <= n; j++)
				for (ll y = 1; y <= n; y++)
					if (color[j] != color[y])
						dp[i + 1][y] = min(dp[i + 1][y], dp[i][j] + a[j][y]);
		ans = min(ans, dp[k][1]);
	}
	cout << ans;
	return 0;
}