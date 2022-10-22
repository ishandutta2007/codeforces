#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

map <int, int> cnt;
vector <int> all[300010];
vector <int> alive;
int pos[300010];
vector <int> G[300010];
vector <int> ALL;
int ID[300010];
int a[300010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		cnt.clear(), alive.clear();
		for (int i = 1; i <= n; i++) {
			all[i].clear();
		}
		ALL.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			ALL.push_back(a[i]);
			cnt[a[i]]++;
		}
		sort(ALL.begin(), ALL.end()), ALL.resize(unique(ALL.begin(), ALL.end()) - ALL.begin());
		auto GetId = [&](int x) -> int {return lower_bound(ALL.begin(), ALL.end(), x) - ALL.begin();};
		for (int i = 0; i < ALL.size(); i++) {
			G[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			int x, y; scanf("%d%d", &x, &y);
			int ix = GetId(x), iy = GetId(y);
			G[ix].push_back(y);
			G[iy].push_back(x);
		}
		for (auto it : cnt) {
			all[it.se].push_back(it.fi);
		}
		for (int i = 1; i <= n; i++) {
			if (all[i].size()) {
				ID[i] = alive.size();
				alive.push_back(i);
				sort(all[i].rbegin(), all[i].rend());
			}
		}
		int N = alive.size();
		long long ans = -1;
		for (auto it : cnt) {
			int x = it.fi, cx = it.se, id = GetId(x);
			vector <int> &bad = G[id];
			bad.push_back(x);
			sort(bad.rbegin(), bad.rend());
			N = upper_bound(alive.begin(), alive.end(), cx) - alive.begin();
			for (int i = 0; i < N; i++) {
				pos[i] = 0;
			}
			for (auto y : bad) {
				int cy = cnt[y], &p = pos[ID[cy]];
				if (p < all[cy].size() && all[cy][p] == y) p++;
			}
			for (int i = 0; i < N; i++) {
				if (pos[i] < all[alive[i]].size()) ans = max(ans, 1ll * (cx + alive[i]) * (x + all[alive[i]][pos[i]]));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}