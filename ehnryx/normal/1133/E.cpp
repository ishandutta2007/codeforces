#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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



//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	unordered_map<int,int> cnt;
	set<int> order;
	order.insert(-7);
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
		order.insert(a);
	}

	int vals[n+1];
	int iid = 0;
	for (int it : order) {
		vals[iid++] = it;
	}

	int dp[k+1][n+7];
	memset(dp, 0, sizeof dp);
	int ans = 0;
	for (int i=1; i<=k; i++) {
		dp[i][0] = 0;
		for (int jd=1; jd<iid; jd++) {
			int v = vals[jd];
			if (v<0) continue;
			int cur = cnt[v];
			int id = jd;
			int res = max(cur + dp[i-1][id-1], dp[i][id-1]);
			for (int j=v-1; j>=v-5; j--) {
				if (cnt.count(j)) {
					--id;
					cur += cnt[j];
					res = max(res, cur + dp[i-1][id-1]);
				}
			}
			ans = max( ans, dp[i][jd] = res );
		}
	}
	cout << ans << nl;

	return 0;
}