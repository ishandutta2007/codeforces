//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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

const int N = 75 + 1;
int dp[N][N], pre[N][N];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		vector<tuple<int,int,int>> ev;
		for(int i=1; i<=n; i++) {
			int a, b;
			cin >> a >> b;
			ev.emplace_back(b, a, i);
		}
		sort(ev.begin(), ev.end());

		memset(dp, -1, sizeof dp);
		dp[0][0] = 0;
		for(int i=1; i<=n; i++) {
			auto [b, a, _] = ev[i-1];
			for(int j=0; j<=k; j++) {
				// skip
				if(dp[i-1][j] != -1) {
					dp[i][j] = dp[i-1][j] + (k-1)*b;
					pre[i][j] = j;
				}
				// take
				if(j > 0 && dp[i-1][j-1] != -1) {
					int val = dp[i-1][j-1] + a + (j-1)*b;
					if(val > dp[i][j]) {
						dp[i][j] = val;
						pre[i][j] = j-1;
					}
				}
			}
		}
		assert(dp[n][k] != -1);

		vector<int> ans;
		for(int i=n, j=k; i>0; i--) {
			if(pre[i][j] == j-1) {
				ans.push_back(get<2>(ev[i-1]));
			}
			j = pre[i][j];
		}
		reverse(ans.begin(), ans.end());
		int last = ans.back();
		ans.pop_back();
		for(int i=n, j=k; i>0; i--) {
			if(pre[i][j] == j) {
				ans.push_back(get<2>(ev[i-1]));
				ans.push_back(-get<2>(ev[i-1]));
			}
			j = pre[i][j];
		}
		ans.push_back(last);

		cout << ans.size() << nl;
		for(int it : ans) {
			cout << it << " ";
		}
		cout << nl;
	}

	return 0;
}