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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> s(n+1);
	rep(i,0,n) {
		cin >> a[i];
		s[a[i]].push_back(i);
	}
	vector<vector<int>> dp(n+1, vector<int>(n+1, n));
	vector<vector<int>> dp2(n+1, vector<int>(n+1, n));
	rep(len,0,n+1) {
		rep(l,0,n-len+1) {
			int r = l+len;
			if (len == 0) {
				dp[l][r] = 0;
				dp2[l][r] = 0;
				continue;
			}
			if (len == 1) {
				dp[l][r] = 1;
				dp2[l][r] = 0;
				continue;
			}
			dp[l][r] = dp[l+1][r] + 1;
			dp[l][r] = min(dp[l][r], dp[l][r-1] + 1);
			int ind = 0;
			while (s[a[l]][ind] < l)
				++ind;
			assert(s[a[l]][ind] == l);
			int i = ind + 1;
			dp2[l][r] = dp[l+1][r];
			while (i < sz(s[a[l]]) && s[a[l]][i] < r) {
				int mid = s[a[l]][i];
				dp2[l][r] = min(dp2[l][r], dp[l+1][mid] + dp2[mid][r]);
				++i;
			}
			dp[l][r] = min(dp[l][r], dp2[l][r] + 1);
		}
	}
	cout << dp[0][n]-1 << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}