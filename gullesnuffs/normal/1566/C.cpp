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
	string s[2];
	cin >> s[0] >> s[1];
	vector<int> dp(n+1);
	rep(i,0,n) {
		rep(j,1,3) {
			if (i+j > n)
				continue;
			set<int> S;
			rep(k,0,2) {
				S.insert(s[k][i] - '0');
				if (j == 2)
					S.insert(s[k][i+1] - '0');
			}
			int MEX = 0;
			while (S.count(MEX)) ++MEX;
			dp[i+j] = max(dp[i+j], dp[i] + MEX);
		}
	}
	cout << dp[n] << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}