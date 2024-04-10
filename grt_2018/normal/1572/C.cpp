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


int t;
const int nax = 3000 + 10, INF = 1e9 + 10;
int n;
int a[nax];
vi occ[nax];
int dp[nax][nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			occ[i].clear();
		}
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			occ[a[i]].PB(i);
		}
		for(int l = 2; l <= n; ++l) {
			for(int i = 1; i <= n; ++i) {
				int j = i + l - 1;
				int best = INF;
				best = dp[i + 1][j] + 1;
				for(int x : occ[a[i]]) {
					if(x > i && x <= j) {
						best = min(best, dp[i + 1][x - 1] + (i + 1 != x) + dp[x][j]);
					}
				}
				dp[i][j] = best;
			}
		}
		cout << dp[1][n] << "\n";
	}
		
}