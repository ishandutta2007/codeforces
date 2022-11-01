#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

vector <int> svi;
string s;
vector <vector <int> > dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		cin >> s;
		svi.clear();
		svi.resize(n);
		dp.clear();
		dp.resize(2, vector <int>(n, 0));
		REP(i, n) {
			cin >> svi[i];
			if(!i) {
				if(s[i] == '1') dp[0][i] = svi[i];
				else dp[1][i] = svi[i];
				continue;
			}
			if(s[i] == '1') {
				dp[0][i] = max(dp[0][i - 1] + svi[i], dp[1][i - 1]);
				dp[1][i] = dp[1][i - 1] + svi[i];
			}
			else {
				dp[0][i] = dp[0][i - 1];
				dp[1][i] = dp[0][i - 1] + svi[i];
			}
			//cout << i << " " << dp[1][i] << "\n";
		}
		cout << dp[0][n - 1] << "\n";
	}
	return 0;
}