#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii a[110];
vector <int> all;
int dp[110][310];
int L[110], R[110], maxj[310];

void chmax(int &a, int b) {
	a = max(a, b);
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].fi, &a[i].se);
		all.push_back(a[i].fi), all.push_back(a[i].fi + a[i].se), all.push_back(a[i].fi - a[i].se);
	}
	a[0].fi = -0x3f3f3f3f, a[0].se = 0;
	all.push_back(-0x3f3f3f3f);
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= n; i++) {
		L[i] = lower_bound(all.begin(), all.end(), a[i].fi) - all.begin();
		R[i] = lower_bound(all.begin(), all.end(), a[i].fi + a[i].se) - all.begin();
	}
	memset(dp, -1, sizeof(dp)), memset(maxj, -1, sizeof(maxj));
	dp[0][L[0]] = dp[0][R[0]] = a[0].se;
	int ans = a[0].se;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < all.size(); j++) {
			if (dp[i][j] == -1) continue;
			chmax(ans, dp[i][j]);
			int maxj = -1;
			for (int k = i + 1; k <= n; k++) {
				maxj = max(maxj, L[k]);
				chmax(dp[k][maxj], dp[i][j] + min(all[maxj] - a[k].fi + a[k].se, all[maxj] - all[j]));
				maxj = max(maxj, R[k]);
				chmax(dp[k][maxj], dp[i][j] + min(all[maxj] - a[k].fi, all[maxj] - all[j]));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}