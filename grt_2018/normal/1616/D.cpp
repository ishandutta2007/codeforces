#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 500 * 100 + 10, INF = 1e8;
int t, n;
int dp[nax][4];
int a[nax], x;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 5; i < n + 5; ++i) {
			cin >> a[i];
		}
		a[0] = a[1] = a[2] = a[3] = a[4] = -INF;
		cin >> x;
		for(int i = 5; i < n + 5; ++i) {
			for(int len = 0; len <= 3; ++len) {
				if(len == 2) {
					if(a[i] + a[i - 1] < 2 * x) {
						dp[i][len] = -INF;
						continue;
					}
				}
				if(len == 3) {
					if(a[i] + a[i - 1] < 2 * x || a[i] + a[i-1]+a[i-2] < 3*x) {
						dp[i][len] = -INF;
						continue;
					}
				}
				dp[i][len] = 0;
				if(len > 0) {
					dp[i][len] = max(dp[i][len], dp[i-1][len-1] + 1);
				} else {
					for(int j = 0; j <= 3; ++j) {
						dp[i][len] = max(dp[i][len], dp[i-1][j]);
					}
				}
				if(len == 3) {
					dp[i][len] = max(dp[i][len], dp[i - 1][len] + 1);
				}
			}
		}
		int ans = 0;
		for(int len = 0; len <= 3; ++len) {
			ans = max(ans, dp[n + 4][len]);
		}
		cout << ans << "\n";
	}
}