#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, x;
	cin >> n >> x;

	ll a[n+1];
	FOR(i,1,n) {
		cin >> a[i];
	}

	ll dp[n+1][3];
	memset(dp, 0, sizeof dp);
	ll ans = 0;
	FOR(i,1,n) {
		For(j,3) {
			if (j == 1) {
				dp[i][j] = max(dp[i][j], dp[i-1][j] + x*a[i]);
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + x*a[i]);
			} else {
				dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i]);
				if (j == 2) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << nl;

	return 0;
}