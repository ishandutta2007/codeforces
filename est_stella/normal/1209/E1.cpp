#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0)
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 1e18;
const int inf = 1e9;

int n, m;
int a[10][111];
int dp[111][111];

int solve() {
	cin >> n >> m;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}

	for(int i=1; i<=m; i++) {
		for(int j=0; j<(1<<n); j++) {
			dp[i][j] = 0;
			for(int k=0; k<(1<<n); k++) {
				if((j & k) == k) {
					for(int l=0; l<n; l++) {
						int sum = 0;
						for(int t=0; t<n; t++) {
							if((1 << ((l + t) % n)) & k) {
								sum += a[t][i-1];
							}
						}

						dp[i][j] = max(dp[i][j], sum + dp[i-1][j^k]);
					}
				}
			}
		}
	}

	cout << dp[m][(1<<n) - 1] << "\n";
}

int main() {
	fast;
	int t;
	cin >> t;

	while(t--) {
		solve();
	}
}