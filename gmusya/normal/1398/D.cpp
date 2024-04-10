#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int R, G, B;
	cin >> R >> G >> B;
	vector <int> r(R), g(G), b(B);
	for (int i = 0; i < R; i++)
		cin >> r[i];
	for (int i = 0; i < G; i++)
		cin >> g[i];
	for (int i = 0; i < B; i++)
		cin >> b[i];
	sort(r.rbegin(), r.rend());
	sort(g.rbegin(), g.rend());
	sort(b.rbegin(), b.rend());
	int ans = 0;
	vector <vector <vector <int>>> dp(R + 1, vector <vector<int>>(G + 1, vector<int>(B + 1)));
	for (int i = 0; i <= R; i++)
		for (int j = 0; j <= G; j++)
			for (int z = 0; z <= B; z++) {
				if (i && j) dp[i][j][z] = max(dp[i][j][z], dp[i - 1][j - 1][z] + r[i - 1] * g[j - 1]);
				if (i && z) dp[i][j][z] = max(dp[i][j][z], dp[i - 1][j][z - 1] + r[i - 1] * b[z - 1]);
				if (j && z) dp[i][j][z] = max(dp[i][j][z], dp[i][j - 1][z - 1] + g[j - 1] * b[z - 1]);
				ans = max(ans, dp[i][j][z]);
			}
	cout << ans;
	return 0;
}