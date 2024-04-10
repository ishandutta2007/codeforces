#include <bits/stdc++.h>
using namespace std;

int dp[210][210];
int last[210][210];
char ans[210];

void get_ans(int x, int y, int p) {
	ans[x] = p + '0';
	if (x == 1 && y == 0) return ;
	if (x == y + 1) get_ans(y, last[x][y], p ^ 1);
	else get_ans(x - 1, y, p);
}

int main () {
	int n; cin >> n;
	string s; cin >> s;
	s = "A" + s;
	dp[1][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (!dp[i][j]) continue;
			if (s[i] <= s[i + 1]) dp[i + 1][j] = 1;
			if (s[j] <= s[i + 1]) dp[i + 1][i] = 1, last[i + 1][i] = j;
		}
	}
	for (int i = 0; i < n; i++) {
		if (dp[n][i]) {
			get_ans(n, i, 1);
			ans[n + 1] = '\0';
			printf("YES\n%s\n", ans + 1);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}