#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int a[1000010];
vector <int> all[5010];
int f[5010][1 << 13], g[5010][1 << 13];
int ans[1 << 13];

void chmin(int &x, int y) {
	x = min(x, y);
}

int GetNxt(int v, int x) {
	return !all[v].size() || x > all[v].back() ? INF : *lower_bound(all[v].begin(), all[v].end(), x);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		all[a[i]].push_back(i);
	}
	memset(f, 0x3f, sizeof(f)), memset(g, 0x3f, sizeof(g));
	f[0][0] = 0;
	for (int i = 0; i <= 5000; i++) {
		for (int j = 0; j < (1 << 13); j++) {
			chmin(f[i][j ^ i], GetNxt(i, g[i][j]));
		}
		for (int j = 0; j < (1 << 13); j++) {
			if (f[i][j] != INF) ans[j] = 1;
			chmin(g[i + 1][j], f[i][j]);
			chmin(g[i + 1][j], g[i][j]);
		}
	}
	int tot = 0;
	for (int i = 0; i < (1 << 13); i++) {
		tot += ans[i];
	}
	printf("%d\n", tot);
	for (int i = 0; i < (1 << 13); i++) {
		if (ans[i]) printf("%d ", i);
	}
	printf("\n");
	return 0;
}