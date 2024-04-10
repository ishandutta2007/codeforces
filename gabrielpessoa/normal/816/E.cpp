#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 5005;

vector<int> g[ms];
int ant[ms];
int sz[ms];
ll dp[ms][ms];
ll aux[ms][ms];
int auxSz[ms];
pair<ll, int> orderedCosts[ms];

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	ll b;
	memset(dp, 63, sizeof dp);
	cin >> n >> b;
	for(int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		orderedCosts[i] = {a, i};
		dp[i][1] = a-b;
		if(i) cin >> ant[i];
		ant[i]--;
		if(i) g[ant[i]].push_back(i);
	}
	sort(orderedCosts, orderedCosts + n);
	for(int i = 0; i < n; i++) {
		ll change = orderedCosts[i].first;
		for(int x = orderedCosts[i].second; x > -1; x = ant[x]) {
			aux[x][auxSz[x]+1] = aux[x][auxSz[x]] + change;
			auxSz[x]++;
		}
	}
	for(int i = n - 1; i > -1; i--) {
		sz[i] = 1;
		for(int c : g[i]) {
			for(int j = sz[i]; j > 0; j--) {
				for(int k = sz[c]; k > 0; k--) {
					dp[i][j+k] = min(dp[i][j+k], dp[i][j] + dp[c][k]);
				}
			}
			sz[i] += sz[c];
		}
		for(int j = 1; j <= sz[i]; j++) {
			dp[i][j] = min(dp[i][j], aux[i][j]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(dp[0][i] <= b) ans = i;
	}
	cout << ans << endl;
}