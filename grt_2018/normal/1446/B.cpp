#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 5000 + 10, INF = 1e9;
int n, m;
string s, t;
int dp[nax][nax];
int ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s >> t;
	for(int i = n - 1; i >= 0; --i) {
		for(int j = m - 1; j >= 0; --j) {
			dp[i][j] = -2;
			if(s[i] != t[j]) {
				if(i != n - 1) dp[i][j] = max(dp[i + 1][j] - 1, dp[i][j]);
				if(j != m-1) dp[i][j] = max(dp[i][j + 1] - 1, dp[i][j]);
			}
			else {
				dp[i][j] = 2;
				if(i == n - 1 || j == m - 1) {
					dp[i][j] = 2;
				} else {
					dp[i][j] = max(dp[i+1][j+1] + 2, dp[i][j]);
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	
}