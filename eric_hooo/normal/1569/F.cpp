#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n, m, k;
long long dp[1 << 12][12];
int G[12][12];
long long pw[20];
vector <pii> match;
int single, lowest, used[20];
set <long long> all[20];
vector <vector <int> > trans;
vector <int> smalltrans;

void GetTrans(int n, int M) {
	if (n == 0) {
		trans.push_back(smalltrans);
		return ;
	}
	for (int i = 0; i <= M; i++) {
		smalltrans.push_back(i);
		GetTrans(n - 1, M + (i == M));
		smalltrans.pop_back();
	}
}

int GetM(long long id) {
	int maxj = 0;
	for (int i = 0; i < n; i++) {
		maxj = max((long long)maxj, id / pw[i] % 12);
	}
	return maxj + 1;
}

long long f[1 << 6][6][2];

void dfs(int now, long long id, int one) {
	if (now * 2 + one == n) {
		memset(f, 0, sizeof(f));
		for (int i = 0; i < now; i++) {
			f[1 << i][i][0] = f[1 << i][i][1] = G[match[i].fi][match[i].se];
		}
		for (int mask = 0; mask < (1 << now); mask++) {
			for (int i = 0; i < now; i++) if ((mask >> i & 1)) {
				int x = match[i].fi, y = match[i].se;
				for (int p = 0; p < 2; p++) if (f[mask][i][p]) {
					for (int j = 0; j < now; j++) if (!(mask >> j & 1)) {
						int xx = match[j].fi, yy = match[j].se;
						for (int q = 0; q < 2; q++) {
							if (G[x][xx] && G[y][yy]) f[mask | 1 << j][j][q] += f[mask][i][p];
							swap(xx, yy);
						}
					}
					swap(x, y);
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i < now; i++) {
			for (int p = 0; p < 2; p++) {
				ans += f[(1 << now) - 1][i][p];
			}
		}
		if (ans) all[GetM(id)].insert(id);
		return ;
	}
	int oldlowest = lowest, rnk = now + one;
	while (used[lowest]) lowest++;
	if ((n & 1) && !one) used[lowest] = 1, dfs(now + 1, id + rnk * pw[lowest], 1), used[lowest] = 0;
	for (int i = lowest + 1; i < n; i++) if (!used[i]) {
		used[lowest] = used[i] = 1, match.push_back(mp(lowest, i));
		dfs(now + 1, id + rnk * pw[lowest] + rnk * pw[i], one);
		used[lowest] = used[i] = 0, match.pop_back();
	}
	lowest = oldlowest;
}

int main() {
	pw[0] = 1; for (int i = 1; i <= 12; i++) pw[i] = pw[i - 1] * 12;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		G[x][y] = G[y][x] = 1;
	}
	for (int i = 0; i < n; i++) {
		dp[1 << i][i] = 1;
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) if (dp[mask][i]) {
			for (int j = 0; j < n; j++) if (!(mask >> j & 1) && G[i][j]) {
				dp[mask | 1 << j][j] += dp[mask][i];
			}
		}
	}
	dfs(0, 0, 0);
	for (int i = 1; i <= n; i++) {
		if (!all[i].size()) continue;
		trans.clear(), GetTrans(i, 0);
		for (auto id : all[i]) {
			for (auto tr : trans) {
				long long nid = 0;
				for (int i = 0; i < n; i++) {
					nid += tr[id / pw[i] % 12] * pw[i];
				}
				if (id != nid) all[GetM(nid)].insert(nid);
			}
		}
	}
	long long ans = 0, pw = 1;
	for (int i = 1; i <= n; i++) {
		pw = pw * (k - i + 1);
		ans += pw * all[i].size();
	}
	printf("%lld\n", ans);
	return 0;
}