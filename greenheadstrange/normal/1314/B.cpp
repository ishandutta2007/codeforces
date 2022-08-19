#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int fl[maxn];
int dp[20][maxn][2][2];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		fl[x - 1] = 1;
	}
	const int inf = 1e9;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < (1 << n); j += (1 << i)) {
			dp[i][j][0][0] = dp[i][j][0][1] = dp[i][j][1][0] = dp[i][j][1][1] = -inf;
			if (i == 1) {
				int cnt = fl[j] + fl[j + 1];
				for (int k = 0; k < 2; k++)
					for (int l = 0; l < 2; l++)
						if (k + l == cnt) dp[i][j][k][l] = (cnt > 0);
			}
			else {
				int u[2], v[2];
				for (u[0] = 0; u[0] < 2; u[0]++)
					for (v[0] = 0; v[0] < 2; v[0]++)
						for (u[1] = 0; u[1] < 2; u[1]++)
							for (v[1] = 0; v[1] < 2; v[1]++) {
								int cost = dp[i - 1][j][u[0]][v[0]] + dp[i - 1][j + (1 << (i - 1))][u[1]][v[1]];
								if (u[0] || u[1]) cost++;
								if (v[0] || v[1]) cost++;
								for (int t1 = 0; t1 < 2; t1++)
									for (int t2 = 0; t2 < 2; t2++) {
										int nc = cost;
										int f1 = u[t1], f2 = v[t2];
										int ed = u[t1 ^ 1];
										if (f1 || f2) nc++;
									//	if (i == 2 && j == 4 && cost == 3)
									//		cout << "???" << u[0] << ' ' << v[0] << ''
										dp[i][j][ed][f1] = max(dp[i][j][ed][f1], nc);
										dp[i][j][ed][f2] = max(dp[i][j][ed][f2], nc);
									} 
							}		
			}
		//	for (int k = 0; k < 2; k++)
		//		for (int l = 0; l < 2; l++)
		//			cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[i][j][k][l] << endl;
		}
	int ans = 0;
	for (int s = 0; s < 2; s++)	
		for (int t = 0; t < 2; t++) {
			int cur = dp[n][0][s][t];
			if (s + t) cur++;
			ans = max(ans, cur);
		}
	cout << ans << endl;
	return 0;
}