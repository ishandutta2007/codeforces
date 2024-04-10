#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 15;
int dp[N][1<<N][N]; /* num, bm, pos -> min value
* num: number of groups
* bm:  mask of used elements
* pos: position of last group
*/
tuple<int,int,int> pre[N][1<<N][N];
int sum[1<<N];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	memset(dp, INF, sizeof dp);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}

		for(int bm=1; bm<1<<n; bm++) {
			int first = -1;
			sum[bm] = 0;
			for(int j=0; j<n; j++) {
				if(!(bm & 1<<j)) continue;
				sum[bm] += a[j];
				if(first == -1) {
					first = j;
				}
			}
			dp[0][bm][first] = sum[bm];
			pre[0][bm][first] = make_tuple(0, 0, 0);
		}

		for(int i=1; i<n; i++) {
			for(int bm=1; bm<1<<n; bm++) {
				for(int j=i; j<n; j++) {
					if(!(bm & 1<<j)) continue;
					dp[i][bm][j] = INF;
					int mask = (1<<j) - 1;
					if(bm & mask) {
						int last = 31 - __builtin_clz(bm & mask);
						dp[i][bm][j] = dp[i][bm][last];
						pre[i][bm][j] = make_tuple(i, bm, last);
					}
					for(int pm=bm^1<<j; pm; pm=(pm-1)&(bm^1<<j)) {
						if(!(pm & mask)) continue;
						int k = 31 - __builtin_clz(pm & mask);
						int sm = bm ^ pm;
						if(sum[sm] > dp[i-1][pm][k] && sum[sm] < dp[i][bm][j]) {
							dp[i][bm][j] = sum[sm];
							pre[i][bm][j] = make_tuple(i-1, pm, k);
						}
					}
				}
			}
		}

		vector<pair<int,int>> ans;
		int bm = (1<<n)-1;
		bool ok = false;
		for(int i=n-1; !ok && i>=0; i--) {
			for(int j=i; !ok && j<n; j++) {
				if(dp[i][bm][j] == INF) continue;
				ok = true;
				while(bm > 0) {
					auto [_, pm, __] = pre[i][bm][j];
					int sm = bm ^ pm;
					for(int k=0; k<n; k++) {
						if(k == j || !(sm & 1<<k)) continue;
						ans.emplace_back(k+1, j+1);
					}
					tie(i, bm, j) = pre[i][bm][j];
				}
			}
		}
		reverse(ans.begin(), ans.end());

		//cerr<<nl;
		//cerr<<"original answer:"<<nl; for(auto [x, y] : ans) {
		//cerr<<x<<" -> "<<y<<nl; }
		//cerr<<nl;

		int m = ans.size();
		cout << m << nl;
		for(int i=0; i<m; i++) {
			cout << ans[i].first << " " << ans[i].second << nl;
			for(int j=i+1; j<m; j++) {
				ans[j].first -= (ans[j].first > ans[i].first);
				ans[j].second -= (ans[j].second > ans[i].first);
			}
		}
	}

	return 0;
}