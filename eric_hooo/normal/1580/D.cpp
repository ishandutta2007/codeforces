#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n, m;
vector <int> from[4010];
int wei[4010];
long long dp[4010][4010];
int a[4010];

void chmax(long long &x, long long y) {
	x = max(x, y);
}

int Build(int l, int r) {
	if (l > r) return 0;
	int p = l;
	for (int i = l; i <= r; i++) {
		if (a[i] < a[p]) p = i;
	}
	int ls = Build(l, p - 1), rs = Build(p + 1, r);
	if (ls) from[p].push_back(ls), wei[ls] = a[ls] - a[p];
	if (rs) from[p].push_back(rs), wei[rs] = a[rs] - a[p];
	return p;
}

int dfs(int x) {
	int sz = 1; dp[x][0] = dp[x][1] = 0;
	for (auto v : from[x]) {
		int ss = dfs(v);
		for (int i = min(sz, m); i >= 0; i--) {
			for (int j = 0; j <= min(ss, m); j++) {
				if (i + j <= m) chmax(dp[x][i + j], dp[x][i] + dp[v][j]);
			}
		}
		sz += ss;
	}
	for (int i = 0; i <= m; i++) {
		dp[x][i] += 1ll * i * (m - i) * wei[x];
	}
	return sz;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int rt = Build(1, n);
	dfs(rt);
	printf("%lld\n", dp[rt][m]);
	return 0;
}