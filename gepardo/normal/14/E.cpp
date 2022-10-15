#include <iostream>
#define int long long

using namespace std;

int n, t;
int dp[30][30][30][5][2];

main()
{
	cin >> n >> t;
	dp[2][0][0][1][0] = 0;
	dp[2][0][0][1][1] = 3;
	dp[2][0][0][2][0] = 1; 
	dp[2][0][0][2][1] = 2;
	dp[2][0][0][3][0] = 2;
	dp[2][0][0][3][1] = 1;
	dp[2][0][0][4][0] = 3;
	dp[2][0][0][4][1] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= t; j++)
			for (int p = 0; p <= t; p++)
				for (int k = 1; k <= 4; k++)
				{
					//cout << i << " " << j << " " << p << " " << k << " : " 
					//<< dp[i][j][p][k][0] << " " << dp[i][j][p][k][1] << endl;
					if (dp[i][j][p][k][0] != 0)
					{
						for (int l = 1; l < k; l++)
							dp[i + 1][j + 1][p][l][1] += dp[i][j][p][k][0];
						for (int l = k + 1; l <= 4; l++)
							dp[i + 1][j][p][l][0] += dp[i][j][p][k][0];
					}
					if (dp[i][j][p][k][1] != 0)
					{
						for (int l = 1; l < k; l++)
							dp[i + 1][j][p][l][1] += dp[i][j][p][k][1];
						for (int l = k + 1; l <= 4; l++)
							dp[i + 1][j][p + 1][l][0] += dp[i][j][p][k][1];	
					}
				}
	int ans = 0;
	for (int i = 1; i <= 4; i++)
		ans += dp[n][t][t - 1][i][0] + dp[n][t][t - 1][i][1];
	cout << ans;
}