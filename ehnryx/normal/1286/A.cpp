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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	int a[n+1];
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	int dp[n+2][n+2][n+2][2];
	memset(dp, INF, sizeof dp);
	dp[0][n/2][(n+1)/2][0] = 0;
	dp[0][n/2][(n+1)/2][1] = 0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			for(int k=0; k<=n; k++) {
				if(a[i] != 0) {
					int t = a[i]%2;
					if(t == 0) {
						dp[i][j][k][t] = min(dp[i][j][k][t], dp[i-1][j+1][k][t]);
						dp[i][j][k][t] = min(dp[i][j][k][t], dp[i-1][j+1][k][t^1] + 1);
					} else {
						dp[i][j][k][t] = min(dp[i][j][k][t], dp[i-1][j][k+1][t]);
						dp[i][j][k][t] = min(dp[i][j][k][t], dp[i-1][j][k+1][t^1] + 1);
					}
				} else {
					dp[i][j][k][0] = min(dp[i][j][k][0], dp[i-1][j+1][k][0]);
					dp[i][j][k][0] = min(dp[i][j][k][0], dp[i-1][j+1][k][1] + 1);
					dp[i][j][k][1] = min(dp[i][j][k][1], dp[i-1][j][k+1][1]);
					dp[i][j][k][1] = min(dp[i][j][k][1], dp[i-1][j][k+1][0] + 1);
				}
			}
		}
	}
	cout << min(dp[n][0][0][0], dp[n][0][0][1]) << nl;


	return 0;
}