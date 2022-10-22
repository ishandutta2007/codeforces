#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[200010];
vector <int> G[200010];
long long ans = 0;

pii dfs(int x, int last) {
	vector <pii> all;
	for (auto v : G[x]) {
		if (v == last) continue;
		pii tmp = dfs(v, x);
		all.push_back(tmp);
	}
	sort(all.rbegin(), all.rend());
	if (all.size() > 1 && all[0].se <= all[1].fi) all[0].se = 0;
	if (!all.size()) {
		ans += a[x];
		return mp(a[x], a[x]);
	}
	if (a[x] > all[0].fi) {
		ans += a[x] - all[0].fi;
		if (x == last) {
			int maxj = all.size() > 1 ? all[1].fi : 0;
			ans += a[x] - maxj;
		}
		return mp(a[x], a[x]);
	}
	if (all.size() == 1) {
		if (x == last) {
			ans += a[x];
		}
		return mp(all[0].fi, max(all[0].se, a[x]));
	}
	if (a[x] <= all[1].fi) {
		return all[0];
	}
	if (x == last) {
		int maxj = all.size() > 1 ? all[1].fi : 0;
		ans += a[x] - maxj;
	}
	return mp(all[0].fi, max(all[0].se, a[x]));
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int maxj = 0;
	for (int i = 1; i <= n; i++) {
		maxj = max(maxj, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (maxj == a[i]) {
			pii tmp = dfs(i, i);
			printf("%lld\n", ans);
			return 0;
		}
	}
	return 0;
}