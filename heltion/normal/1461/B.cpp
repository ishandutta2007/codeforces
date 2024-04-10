#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 500 + 2;
char s[maxn][maxn];
int dp[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	for(cin >> T; T; T -= 1){
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i += 1) cin >> (s[i] + 1);
		int ans = 0;
		for(int i = n; i; i -= 1)
			for(int j = m; j; j -= 1){
				dp[i][j] = 0;
				if(s[i][j] == '*'){
					if(i < n and j > 1 and j < m) dp[i][j] = 1 + min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]});
					else dp[i][j] = 1;
				}
				ans += dp[i][j];
			}
		cout << ans << "\n";
	}
	return 0;
}