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

int count(int x, int r) {
	return (x+r)/3;
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, l, r;
	cin >> n >> l >> r;

	int cnt[3];
	for (int i=0; i<3; i++) {
		cnt[(3-i)%3] = count(r,i) - count(l-1,i);
	}

	ll dp[n+1][3];
	memset(dp, 0, sizeof dp);

	dp[0][0] = 1;
	for (int i=1; i<=n; i++) {
		for (int a=0; a<3; a++) {
			for (int j=0; j<3; j++) {
				dp[i][a] += cnt[j]*dp[i-1][(a+3-j)%3] % MOD;
			}
			dp[i][a] %= MOD;
		}
	}
	cout << dp[n][0] << nl;

	return 0;
}