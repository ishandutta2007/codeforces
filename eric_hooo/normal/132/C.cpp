#include <bits/stdc++.h>
using namespace std;

int dp[110][210][60][2];

int main(){
	string s; cin >> s;
	int m = s.length();
	s = " " + s;
	int n; cin >> n;
	dp[0][101][0][0] = 1;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= 201; j++){
			for (int k = 0; k <= n; k++){
				for (int p = 0; p < 2; p++){
					if (s[i] == 'F'){
						for (int t = 0; t <= k; t++){
							if (t % 2 == 0) dp[i][j][k][p] |= dp[i - 1][j + (p ? -1 : 1)][k - t][p];
							else dp[i][j][k][p] |= dp[i - 1][j][k - t][p ^ 1];
						}
					} else {
						for (int t = 0; t <= k; t++){
							if (t % 2 == 0) dp[i][j][k][p] |= dp[i - 1][j][k - t][p ^ 1];
							else dp[i][j][k][p] |= dp[i - 1][j + (p ? -1 : 1)][k - t][p];
						}
					}
				}
			}
		}
	}
	int ans = 101;
	for (int i = 1; i <= 201; i++){
		if (dp[m][i][n][0] || dp[m][i][n][1]) if (abs(ans - 101) < abs(i - 101)) ans = i;
	}
	cout << abs(ans - 101) << endl;
	return 0;
}