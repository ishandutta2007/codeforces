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

const int nax = 500 + 10;
const ll INF = 1e18;
int t, n;
int c[nax][nax];
ll sum_l[nax][nax], sum_u[nax][nax];
ll dp[nax][nax];

ll path() {
	for(int i = 1; i <= 2 * n; ++i) {
		for(int j = 1; j <= 2 * n; ++j) {
			sum_l[i][j] = sum_l[i][j - 1] + c[i][j];
			sum_u[i][j] = sum_u[i - 1][j] + c[i][j];
		}
	}
	for(int i = n; i <= 2 * n; ++i) {
		for(int j = n; j <= 2 * n; ++j) {
			dp[i][j] = min({dp[i - 1][j] + sum_l[i][j] - sum_l[i][j - n], dp[i][j - 1] + sum_u[i][j] - sum_u[i - n][j], dp[i-1][j-1] + sum_l[i][j] - sum_l[i][j - n] + sum_u[i][j] - sum_u[i - n][j] - c[i][j]}) ;
		}
	}
	return dp[2*n][2*n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		ll sum = 0;
		for(int i = 1; i <= 2 * n; ++i) {
			for(int j = 1; j <= 2 * n; ++j) {
				cin >> c[i][j];
				if(i > n && j > n) sum += c[i][j];
			}
		}
		ll ans = INF;
		for(int dx : {0, n}) {
			for(int dy : {0, n}) {
				if(dx + dy != n) continue;
				for(int i : {1, n}) {
					for(int j : {1, n}) {
						ans = min(ans, (ll)c[dx+i][dy+j]);
					}
				}
			}
		}
		//ll ans = path();
		//for(int i = 1; i <= n; ++i) {
			//vi v(n);
			//for(int j = n+1; j <= n*2; ++j) {
				//v[j - n - 1] = c[i][j];
			//}
			//reverse(v.begin(), v.end());
			//for(int j = n + 1; j <= n*2; ++j) {
				//c[i][j] = v[j - n - 1];
			//}
		//}
		//ans = min(ans, path());
		//for(int j = 1; j <= n; ++j) {
			//vi v(n);
			//for(int i = n + 1; i <= 2 * n; ++i) {
				//v[i - n -  1] = c[i][j];
			//}
			//reverse(v.begin(), v.end());
			//for(int i = n + 1; i <= 2 * n; ++i) {
				//c[i][j] = v[i - n - 1];
			//}
		//}
		//ans = min(ans, path());
		//for(int i = 1; i <= n; ++i) {
			//vi v(n);
			//for(int j = n+1; j <= n*2; ++j) {
				//v[j - n - 1] = c[i][j];
			//}
			//reverse(v.begin(), v.end());
			//for(int j = n + 1; j <= n*2; ++j) {
				//c[i][j] = v[j - n - 1];
			//}
		//}
		//ans = min(ans, path());
		cout << ans + sum << "\n";
	}
}