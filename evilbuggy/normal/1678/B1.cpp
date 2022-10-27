#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
pair<int, int> dp[maxn][2];

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	dp[0][0] = {0, 1};
	dp[0][1] = {0, 1};
	for(int i = 1; i <= n; i++){
		int c = s[i - 1] - '0';
		dp[i][0] = {n, n};
		dp[i][1] = {n, n};
		for(int x = 0; x < 2; x++){
			for(int p = 0; p < 2; p++){
				if(i%2 == 0 && x != p)continue;
				pair<int, int> y = dp[i - 1][p];
				if(x != c)y.first++;
				if(x != p)y.second++;
				dp[i][x] = min(dp[i][x], y);
			}
		}
	}
	pair<int, int> ans = min(dp[n][0], dp[n][1]);
	cout << ans.first << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}