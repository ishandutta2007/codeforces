#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mod = 998244353;

typedef pair <int, int> pii;

int L[300010], R[300010], id[300010], sum[300010], sz[300010];
vector <int> node;
vector <pii> all[300010];
int cnt[50][50];
long long dp[50];
int vis[300010];
vector <int> from[300010];
long long fac[300010], inv[300010];

void dfs(int x) {
	vis[x] = 1, node.push_back(x), id[x] = (int)node.size() - 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (vis[v]) continue;
		dfs(v);
	}
}

bool check(int mask) {
	for (int i = 0; i < node.size(); i++) {
		if (mask >> i & 1) {
			int x = node[i];
			for (int j = 0; j < from[x].size(); j++) {
				int v = from[x][j];
				if (mask >> id[v] & 1) return 0;
			}
		}
	}
	return 1;
}

long long power(long long a, long long b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

long long C(int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main () {
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= 300005; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = power(fac[i], mod - 2);
	}
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &L[i], &R[i]);
	}
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	int ALL = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		node.clear(), dfs(i);
		if (node.size() == 1) sum[L[i]]++, sum[R[i] + 1]--;
		else {
			int m = node.size();
			for (int mask = 0; mask < (1 << m); mask++) {
				if (!check(mask)) continue;
				int l = 1, r = n, cnt = 0;
				for (int j = 0; j < m; j++) {
					if (mask >> j & 1) l = max(l, L[node[j]]), r = min(r, R[node[j]]), cnt++;
				}
				if (l > r) continue;
				all[l].push_back(mp(ALL, cnt)), all[r + 1].push_back(mp(ALL, -cnt));
			}
			sz[ALL] = node.size();
			ALL++;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] += sum[i - 1];
		for (int j = 0; j < all[i].size(); j++) {
			int x = all[i][j].fi, y = all[i][j].se;
			if (y > 0) cnt[x][y]++;
			else cnt[x][-y]--;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int j = 0; j < ALL; j++) {
			for (int k = 40; k >= 0; k--) {
				for (int l = 1; l <= sz[j]; l++) {
					if (k - l < 0) break;
					dp[k] = (dp[k] + dp[k - l] * cnt[j][l]) % mod;
				}
			}
		}
		for (int j = 0; j <= 40; j++) {
			if (j > i) break;
			if (i - j <= sum[i]) ans = (ans + dp[j] * C(sum[i], i - j)) % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}