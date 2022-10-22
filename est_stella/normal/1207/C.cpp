#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define INF 1e18
#define inf 1e9
#define pb push_back
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll dp[200010][2];
ll h[200010];

void solve() {
	int n, a, b;
	string s;
	cin >> n >> a >> b;
	cin >> s;

	for(int i=0; i<=n; i++) {
		if(i == n) h[i] = s[i-1]-'0';
		else if(i > 0) h[i] = max(s[i], s[i-1])-'0';
		else h[i] = s[i]-'0';
	}

	dp[0][0] = b;
	dp[0][1] = INF;

	for(int i=1; i<=n; i++) {
		dp[i][0] = dp[i][1] = INF;
		if(h[i] == 0) {
			dp[i][0] = min(dp[i-1][0], dp[i-1][1] + a) + b + a;
			dp[i][1] = min(dp[i-1][1], dp[i-1][0] + a) + 2 * b + a;
		}
		else {
			dp[i][1] = min(dp[i-1][1], dp[i-1][0] + a) + 2 * b + a;
		}
	}

	cout << dp[n][0] << "\n";
}

int main() {
	fast;

	int t;

	cin >> t;
	while(t--) {
		solve();
	}
}