#include <bits/stdc++.h>
using namespace std;

string dp[1 << 8][4];
string ans[1 << 8];
char buf[10];

void chmin(string &a, const string &b) {
	if (a.size() > b.size() || a.size() == b.size() && a > b) a = b;
}

int main () {
	for (int i = 0; i < (1 << 8); i++) {
		for (int j = 0; j < 4; j++) {
			dp[i][j].resize(100);
		}
	}
	dp[15][0] = "x", dp[51][0] = "y", dp[85][0] = "z";
	for (int it = 0; it < 3; it++) {
		for (int i = 0; i < (1 << 8); i++) {
			for (int p = 0; p < 4; p++) {
				if (dp[i][p].size() == 100) continue;
				// 1 - !
				int x = ~i & (1 << 8) - 1; string val = "!";
				assert((x | i) == (1 << 8) - 1 && (x & i) == 0);
				if (p >= 1) val += "(" + dp[i][p] + ")";
				else val += dp[i][p];
				chmin(dp[x][1], val);
				for (int j = 0; j < (1 << 8); j++) {
					for (int q = 0; q < 4; q++) {
						if (dp[j][q].size() == 100) continue;
						int x; string val;
						// 2 - &
						x = i & j, val = "";
						if (p > 2) val += "(" + dp[i][p] + ")";
						else val += dp[i][p];
						val += "&";
						if (q >= 2) val += "(" + dp[j][q] + ")";
						else val += dp[j][q];
						chmin(dp[x][2], val);
						// 3 - |
						x = i | j, val = "";
						if (p > 3) val += "(" + dp[i][p] + ")";
						else val += dp[i][p];
						val += "|";
						if (q >= 3) val += "(" + dp[j][q] + ")";
						else val += dp[j][q];
						chmin(dp[x][3], val);
					}
				}
			}
		}
	}
	for (int i = 0; i < (1 << 8); i++) {
		ans[i].resize(100);
		for (int j = 0; j < 4; j++) {
			chmin(ans[i], dp[i][j]);
		}
	}
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", buf);
		int val = 0;
		for (int i = 0; i < 8; i++) {
			val = val * 2 + buf[i] - '0';
		}
		printf("%s\n", ans[val].c_str());
	}
	return 0;
}