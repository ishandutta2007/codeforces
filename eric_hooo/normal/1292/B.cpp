#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pii;

const long long INF = 0x3f3f3f3f3f3f3f3fll;

long long dp[100][100][2];
vector <pii> node;
int pos;

long long dist(int a, int b) {
	return abs(node[a].fi - node[b].fi) + abs(node[a].se - node[b].se);
}

long long dfs(int l, int r, int p) {
	if (l == r) return 0;
	if (l == pos && p == 0 || r == pos && p == 1) return INF;
	if (~dp[l][r][p]) return dp[l][r][p];
	long long &res = dp[l][r][p] = INF;
	if (p == 0) res = min(res, min(dfs(l + 1, r, 0) + dist(l, l + 1), dfs(l + 1, r, 1) + dist(l, r)));
	else res = min(res, min(dfs(l, r - 1, 1) + dist(r, r - 1), dfs(l, r - 1, 0) + dist(l, r)));
	return res;
}

int main () {
	long long x, y, a, b, c, d; cin >> x >> y >> a >> c >> b >> d;
	long long s, t, T; cin >> s >> t >> T;
	while (1) {
		node.push_back(mp(x, y));
		if ((s + T - b) / x < a || (t + T - d) / y < c) break;
		x = x * a + b, y = y * c + d;
	}
	int ans = 0;
	for (int i = 0; i < node.size(); i++) {
		long long x = node[i].fi, y = node[i].se;
		long long dist = abs(s - x) + abs(t - y);
		if (dist > T) continue;
		int sum = 1; long long ttt = T - dist;
		memset(dp, -1, sizeof(dp)), pos = i;
		for (int l = 0; l <= i; l++) {
			for (int r = i; r < node.size(); r++) {
				if (min(l == i ? INF : dfs(l, r, 0), r == i ? INF : dfs(l, r, 1)) <= ttt) {
					sum = max(sum, r - l + 1);
				}
			}
		}
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}