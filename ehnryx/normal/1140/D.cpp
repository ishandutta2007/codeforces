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

const int N = 500+1;
ll dp[N][N];

ll solve(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (r-l < 2) return dp[l][r] = 0;
	ll res = INFLL;
	for (int i=l+1; i<r; i++) {
		res = min(res, l*r*i + solve(l,i) + solve(i,r));
	}
	return dp[l][r] = res;
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

	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	cout << solve(1,n) << nl;

	return 0;
}