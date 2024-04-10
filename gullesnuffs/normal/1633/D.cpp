#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int cost[10005];

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> b(n);
	vector<int> c(n);
	rep(i,0,n)
		cin >> b[i];
	rep(i,0,n)
		cin >> c[i];
	int L = min(n*15, k);
	vector<ll> dp(L+1);
	dp[0] = 0;
	rep(i,0,n) {
		int C = cost[b[i]];
		rrep(j,L+1-C,0) {
			dp[j+C] = max(dp[j+C], dp[j]+c[i]);
		}
	}
	ll ans = 0;
	rep(j,0,L+1) {
		ans = max(ans, dp[j]);
	}
	cout << ans << endl;
}

int main() {
	rep(a,1,1001) {
		cost[a] = 10000;
	}
	cost[1] = 0;
	rep(a,1,1001) {
		rep(x,1,a+1) {
			cost[a+a/x] = min(cost[a+a/x], cost[a]+1);
		}
		//cout << a << " " << cost[a] << endl;
	}
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}