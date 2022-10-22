#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a-1; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(vector<int> a) {
	int n = sz(a);
	vector<int> dp(n, 1);
	dp[n-1] = 1;
	int ans = 1;
	rrep(i,n-1,0) {
		rep(j,i+1,min(n, i+1100)) {
			if ((a[i]^j) < (a[j]^i)) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i,0,n)
			cin >> a[i];
		solve(a);
	}
}