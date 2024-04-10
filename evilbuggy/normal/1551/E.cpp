#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int a[N], dp[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				dp[i][j] = -1e9;
			}
		}
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= i; j++){
				dp[i][j] = dp[i - 1][j];
				if(j > 0){
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
					if(a[i] == j)dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
				// cout << dp[i][j] << " ";
			}
			// cout << '\n';
		}
		int ans = n + 1;
		for(int j = 1; j <= n; j++){
			if(dp[n][j] >= k)ans = j;
		}
		cout << n - ans << '\n';
	}

	return 0;
}