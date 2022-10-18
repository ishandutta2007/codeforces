#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int dp[3][2][77][77][77];
int moveV[77][77][77];
int moveK[77][77][77];
int moveX[77][77][77];

int main() {
	ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	string s;
	cin >> s;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			for (int a = 0; a < 77; ++a)
				for (int b = 0; b < 77; ++b)
					for (int c = 0; c < 77; ++c)
						dp[i][j][a][b][c] = 1e+9;

	vector<int> V, K, X;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'V') V.push_back(i);
		else if (s[i] == 'K') K.push_back(i);
		else X.push_back(i);
	}

	for (int a = 0; a <= V.size(); ++a) {
		for (int b = 0; b <= K.size(); ++b) {
			for (int c = 0; c <= X.size(); ++c) {
				if (a != V.size()) {
					for (int i = b; i < K.size(); ++i) {
						if (K[i] < V[a]) moveV[a][b][c]++;
					}
					for (int i = c; i < X.size(); ++i) {
						if (X[i] < V[a]) moveV[a][b][c]++;
					}
				}
				if (b != K.size()) {
					for (int i = a; i < V.size(); ++i) {
						if (V[i] < K[b]) moveK[a][b][c]++;
					}
					for (int i = c; i < X.size(); ++i) {
						if (X[i] < K[b]) moveK[a][b][c]++;
					}
				}
				if (c != X.size()) {
					for (int i = a; i < V.size(); ++i) {
						if (V[i] < X[c]) moveX[a][b][c]++;
					}
					for (int i = b; i < K.size(); ++i) {
						if (K[i] < X[c]) moveX[a][b][c]++;
					}
				}
			}
		}
	}

	int cur = 0, nx = 1;

	// V - 0, K - 1, X - 2
	dp[2][cur][0][0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int t = 0; t < 3; ++t) {
			for (int a = 0; a <= V.size(); ++a) {
				for (int b = 0; b <= K.size(); ++b) {
					for (int c = 0; c <= X.size(); ++c) {
						// V
						if (a < V.size()) {
							dp[0][nx][a + 1][b][c] = min(dp[0][nx][a + 1][b][c], moveV[a][b][c] + dp[t][cur][a][b][c]);
						}
						// K
						if (t != 0 && b < K.size()) {
							dp[1][nx][a][b + 1][c] = min(dp[1][nx][a][b + 1][c], moveK[a][b][c] + dp[t][cur][a][b][c]);
						}
						// X
						if (c < X.size()) {
							dp[2][nx][a][b][c + 1] = min(dp[2][nx][a][b][c + 1], moveX[a][b][c] + dp[t][cur][a][b][c]);
						}
					}
				}
			}
		}

		swap(cur, nx);

		for (int i = 0; i < 3; ++i)
			for (int a = 0; a < 77; ++a)
				for (int b = 0; b < 77; ++b)
					for (int c = 0; c < 77; ++c)
						dp[i][nx][a][b][c] = 1e+9;
	}

	int ans = 1e+9;
	for (int t = 0; t < 3; ++t)
		ans = min(ans, dp[t][cur][V.size()][K.size()][X.size()]);

	cout << ans << endl;

	return 0;
}