#include <bits/stdc++.h>
using namespace std;

map <string, int> ID;
int nxt[500010][20];
int dp[1 << 15][110];
char buf[500010];
int a[500010];

string read() {
	scanf("%s", buf);
	return buf;
}

void chmin(int &a, int b) {
	a = min(a, b);
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s = read();
		ID[s] = i;
	}
	int N = n * (n - 1) / 2;
	int ans = -1, p = -1;
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int len; scanf("%d", &len);
		for (int j = 0; j < len; j++) {
			string s = read();
			a[j] = ID.count(s) ? ID[s] : n;
		}
		for (int j = 0; j < n; j++) {
			nxt[len][j] = nxt[len + 1][j] = len;
		}
		for (int j = len - 1; j >= 0; j--) {
			int x = a[j];
			for (int k = 0; k < n; k++) {
				nxt[j][k] = nxt[j + 1][k];
			}
			nxt[j][x] = j;
		}
		for (int mask = 0; mask < (1 << n); mask++) {
			for (int i = 0; i <= N; i++) {
				dp[mask][i] = len + 1;
			}
		}
		dp[0][0] = 0;
		for (int mask = 0; mask < (1 << n); mask++) {
			for (int j = 0; j <= N; j++) {
				if (dp[mask][j] == len + 1) continue;
				int cnt = 0;
				for (int i = 0; i < n; i++) {
					if (mask >> i & 1) cnt++;
				}
				for (int i = 0; i < n; i++) {
					if (mask >> i & 1) {
						cnt--;
						continue;
					}
					chmin(dp[mask | 1 << i][j + cnt], nxt[dp[mask][j]][i] + 1);
				}
			}
		}
		int minj = 0;
		while (minj <= N && dp[(1 << n) - 1][minj] == len + 1) minj++;
		if (minj > N) continue;
		if (ans == -1) ans = minj, p = i + 1;
		else if (ans > minj) ans = minj, p = i + 1;
	}
	if (ans == -1) {
		printf("Brand new problem!\n");
		return 0;
	}
	printf("%d\n", p);
	printf("[:");
	ans = N - ans + 1;
	while (ans--) printf("|");
	printf(":]");
	return 0;
}