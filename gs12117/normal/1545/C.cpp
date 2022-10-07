#include<cstdio>
int n;
int a[1010][510];
const int mod = 998244353;
int state[1010];//0:tbd,1:fix,-1:discard
int cnt[510];
void dfs(int x, int st) {
	state[x] = st;
	for (int i = 0; i < 2 * n; i++) {
		if (state[i] != 0)continue;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == a[x][j]) {
				dfs(i, -st);
				break;
			}
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
			state[i] = 0;
		}
		while (1) {
			int tofix = -1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= n; j++) {
					cnt[j] = 0;
				}
				for (int j = 0; j < 2 * n; j++) {
					if (state[j] != -1) {
						cnt[a[j][i]]++;
					}
				}
				for (int j = 0; j < 2 * n; j++) {
					if (state[j] == 0 && cnt[a[j][i]] == 1) {
						tofix = j;
						break;
					}
				}
				if (tofix != -1)break;
			}
			if (tofix != -1) {
				state[tofix] = 1;
				for (int i = 0; i < 2 * n; i++) {
					if (state[i] != 0)continue;
					for (int j = 0; j < n; j++) {
						if (a[i][j] == a[tofix][j]) {
							state[i] = -1;
						}
					}
				}
			}
			else {
				break;
			}
		}
		int ans = 1;
		for (int i = 0; i < 2 * n; i++) {
			if (state[i] == 0) {
				ans *= 2;
				ans %= mod;
				dfs(i, 1);
			}
		}
		printf("%d\n", ans);
		for (int i = 0; i < 2 * n; i++) {
			if (state[i] == 1) {
				printf("%d ", i + 1);
			}
		}
		printf("\n");
	}
	return 0;
}