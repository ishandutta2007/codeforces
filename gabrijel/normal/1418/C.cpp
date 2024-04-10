#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		vector <int> niz(n + 2, 0);
		vector <pair <int, int> > dp(n + 5, make_pair(0, 0));
		REP(i, n) {
			cin >> niz[i];
		}
		for(int i = n - 1; i >= 0; i--) {
			if(niz[i]) {
				if(niz[i + 1]) {
					dp[i].second = min(dp[i + 1].first + 1, dp[i + 2].first + 2);
				}
				else {
					dp[i].second = min(dp[i + 1].first + 1, dp[i + 2].first + 1);
				}
			}
			else {
				if(niz[i + 1]) {
					dp[i].second = min(dp[i + 1].first, dp[i + 2].first + 1);
				}
				else {
					dp[i].second = min(dp[i + 1].first, dp[i + 2].first);
				}
			}
			dp[i].first = min(dp[i + 1].second, dp[i + 2].second);
		}
		cout << dp[0].second << "\n";
	}
	return 0;
}