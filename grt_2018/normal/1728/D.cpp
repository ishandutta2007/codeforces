//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 2000 + 10;
int t;
int dp[nax][nax];

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	
	for(int i = 1; i <= n; ++i) dp[i][i] = 0;

	for(int len = 2; len <= n; len += 2) {
		for(int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			// take s[i]
			int w1 = 1;
			if(dp[i + 1][j - 1] != 0) {
				w1 = min(w1, dp[i + 1][j - 1]);
			} else {
				if(s[i - 1] > s[j - 1]) w1 = -1;
				else if(s[i - 1] == s[j - 1]) w1 = min(w1, 0);
			}
			
			if(dp[i + 2][j] != 0) {
				w1 = min(w1, dp[i + 2][j]);
			} else {
				if(s[i] < s[i -1]) w1 = -1;
				else if(s[i] == s[i - 1]) w1 = min(w1, 0);
			}
			
			int w2 = 1;

			if(dp[i + 1][j - 1] != 0) {
				w2 = min(w2, dp[i + 1][j - 1]);
			} else {
				if(s[i - 1] < s[j - 1]) w2 = -1;
				else if(s[i - 1] == s[j - 1]) w2 = min(w2, 0);
			}
			
			if(dp[i][j - 2] != 0) {
				w2 = min(w2, dp[i][j - 2]);
			} else {
				if(s[j - 2] < s[j - 1]) w2 = -1;
				else if(s[j - 2] == s[j - 1]) w2 = min(w2, 0);
			}
			
			dp[i][j] = max(w1, w2);
		}
	}
	if(dp[1][n] == 1) {
		cout << "Alice\n";
	} else if(dp[1][n] == -1) {
		cout << "Bob\n";
	} else {
		cout << "Draw\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}