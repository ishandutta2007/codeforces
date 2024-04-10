#include <bits/stdc++.h>
using namespace std;

char s[100010], t[100010];
int n, m;
int nxt[100010];
int to[100010][26];
int f[100010], g[100010];

void chmax(int &x, int y) {
	x = max(x, y);
}

void BuildNxt(char *s, int n) {
	nxt[0] = -1;
	for (int i = 1; i <= n; i++) {
		nxt[i] = nxt[i - 1];
		while (~nxt[i] && s[nxt[i] + 1] != s[i]) nxt[i] = nxt[nxt[i]];
		nxt[i]++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			if (s[i + 1] == 'a' + j) to[i][j] = i + 1;
			else to[i][j] = nxt[i] == -1 ? 0 : to[nxt[i]][j];
		}
	}
}

int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	BuildNxt(t, m);
	for (int j = 0; j < m; j++) {
		f[j] = j == 0 ? 0 : -0x3f3f3f3f;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			g[j] = -0x3f3f3f3f;
		}
		if (s[i] != '?') {
			for (int j = 0; j < m; j++) {
				chmax(g[to[j][s[i] - 'a']], f[j]);
			}
		} else {
			for (int j = m - 1; j >= 0; j--) {
				if (~nxt[j]) chmax(f[nxt[j]], f[j]);
			}
			g[0] = f[0];
			for (int j = 0; j < m; j++) {
				g[j + 1] = f[j];
			}
		}
		chmax(g[nxt[m]], g[m] + 1);
		for (int j = 0; j < m; j++) {
			f[j] = g[j];
		}
	}
	int ans = 0;
	for (int j = 0; j < m; j++) {
		chmax(ans, f[j]);
	}
	printf("%d\n", ans);
	return 0;
}