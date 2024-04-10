#include <bits/stdc++.h>
using namespace std;

int n, x, tot = 1, a[21], ch[20000][9], ed[20000], fail[20000], f[1010][20000];
char s[1010];

void dfs(int cur, int rem) {
	if (!rem) {
		bool flag = 0;
		for (int l = 1; l < cur; l++) {
			for (int r = l, s = 0; r < cur; r++) {
				s += a[r] + 1;
				if (s < x && !(x % s)) flag = 1;
			}
		}
		if (flag) return;
		int v = 1;
		for (int i = 1; i < cur; i++) {
			if (!ch[v][a[i]]) ch[v][a[i]] = ++tot;
			v = ch[v][a[i]];
		}
		ed[v] = 1; return;
	}
	for (int i = 1; i <= min(9, rem); i++) {
		a[cur] = i - 1, dfs(cur + 1, rem - i);
	}
}

int main() {
	scanf("%s %d", s + 1, &x), n = strlen(s + 1);
	dfs(1, x);
	fill(ch[0], ch[0] + 9, 1);
	queue<int> Q; Q.push(1), fail[0] = 1;
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		for (int i = 0; i < 9; i++) {
			if (ch[v][i]) fail[ch[v][i]] = ch[fail[v]][i], Q.push(ch[v][i]);
			else ch[v][i] = ch[fail[v]][i];
		}
	}
	memset(f, 0x3f, sizeof(f)), f[1][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= tot; j++) {
			f[i + 1][j] = min(f[i + 1][j], f[i][j] + 1);
			int nj = ch[j][s[i] - '1'];
			if (!ed[nj]) f[i + 1][nj] = min(f[i + 1][nj], f[i][j]);
		}
	}
	printf("%d\n", *min_element(f[n + 1] + 1, f[n + 1] + tot + 1));
	return 0;
}