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

const int N = 1e6+1;
int cnt[N];
int dp[N][6][6]; // i,rem,rem

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}

	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;
	for (int p=1; p<=m; p++) {
		for (int i=0; i<=5; i++) {
			if (cnt[p] < i) continue;
			for (int j=0; j<=5; j++) {
				for (int take=0; take<=2 && j+take<=5; take++) {
					if (cnt[p]-take < i) continue;
					int cur = (cnt[p]-i-take)/3;
					if (cnt[p]-take-cur*3 == i) {
						for (int k=0; k+take<=5; k++) {
							if (dp[p-1][j+take][k+take] != -1) {
								dp[p][i][j] = max(dp[p][i][j], dp[p-1][j+take][k+take] + take + cur);
							}
						}
					}
				}
				//cerr << p << " " << i << " " << j << " -> " << dp[p][i][j] << nl;
			}
		}
	}

	int ans = 0;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			ans = max(ans, dp[m][i][j]);
		}
	}
	assert(ans != -INF);
	cout << ans << nl;

	return 0;
}