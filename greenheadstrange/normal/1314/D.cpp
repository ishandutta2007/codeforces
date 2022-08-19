#include <bits/stdc++.h>
#define ll long long
#define maxn 85 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n, k;
int eg[maxn][maxn];
int dp[11][maxn];
int col[maxn];
int s[2][maxn], cnt[2];
const int inf = 1200000000;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> eg[i][j];
	srand(time(0));
	int ans = inf;
	for (int i = 0; i < 500000; i++) {
		if (i % 1000 == 0 && 1.0 * clock() / CLOCKS_PER_SEC > 2.5) break;
		cnt[0] = cnt[1] = 0;
		for (int j = 1; j <= n; j++) {
			col[j] = rand() & 1; 
			s[col[j]][cnt[col[j]]++] = j;
		}
		for (int j = k; j >= 0; j--)
			for (int l = 1; l <= n; l++) {
				if (j == k)
					if (l == 1) dp[j][l] = 0;
					else dp[j][l] = inf;
				else {
					dp[j][l] = inf;
					int id = col[l] ^ 1;
					for (int t = 0; t < cnt[id]; t++) {
						int v = s[id][t];
						dp[j][l] = min(dp[j][l], eg[l][v] + dp[j + 1][v]);
					}
				}
			}
		ans = min(ans, dp[0][1]);
	}
	cout << ans << endl;
	return 0;
}