#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 50+1;
ll arr[N];
ll sums[N][N];

int dp[N][N];
int possible(ll mask, int n, int k) {
	if (k == 0) return n == 0;
	if (dp[n][k] != -1) return dp[n][k];

	for (int i=n; i>0; i--) {
		if ((mask & sums[i][n]) == mask && possible(mask, i-1, k-1)) {
			return dp[n][k] = true;
		}
	}

	return dp[n][k] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	for (int i=1; i<=n; i++) {
		cin >> arr[i];
	}

	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			sums[i][j] = sums[i][j-1] + arr[j];
		}
	}

	ll mask = 0;
	for (int i=60; i>=0; i--) {
		memset(dp, -1, sizeof dp);
		if (possible(mask|1LL<<i, n, k)) {
			mask |= 1LL<<i;
		}
	}
	cout << mask << nl;

	return 0;
}