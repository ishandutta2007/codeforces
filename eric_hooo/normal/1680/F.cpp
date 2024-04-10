#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		static vector <int> G[1000010]; for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 0; i < m; i++) {
			int x, y; scanf("%d%d", &x, &y);
			G[x].push_back(y), G[y].push_back(x);
		}
		static int dep[1000010], vis[1000010], sum[1000010]; for (int i = 1; i <= n; i++) vis[i] = sum[i] = 0;
		int tot = 0, BEG = 0;
		function <void(int, int)> dfs; dfs = [&](int x, int last) -> void {
			vis[x] = 1;
			for (auto v : G[x]) if (v != last) {
				if (!vis[v]) dep[v] = dep[x] + 1, dfs(v, x);
				else if (dep[v] > dep[x]) {
					if (dep[x] + dep[v] & 1) sum[v]--, sum[x]++;
					else sum[v]++, sum[x]--, tot++, BEG = dep[x] + 1 & 1;
				}
			}
		};
		function <void(int, int)> GetSum; GetSum = [&](int x, int last) -> void {
			vis[x] = 2;
			for (auto v : G[x]) if (v != last) {
				if (vis[v] == 1) GetSum(v, x), sum[x] += sum[v];
			}
		};
		dep[1] = 0, dfs(1, 1), GetSum(1, 1);
		int TAG = -1;
		for (int i = 2; i <= n; i++) {
			if (sum[i] == tot) {
				TAG = i, BEG = dep[i] & 1;
			}
		}
		if (TAG == -1 && tot > 1) {
			printf("NO\n");
		} else {
			printf("YES\n");
			static int ans[1000010];
			function <void(int, int)> SetAns; SetAns = [&](int x, int cur) -> void {
				vis[x] = 3;
				ans[x] = cur;
				cur ^= 1;
				for (auto v : G[x]) {
					if (vis[v] == 2) SetAns(v, cur ^ (TAG == v));
				}
			};
			SetAns(1, BEG);
			for (int i = 1; i <= n; i++) {
				printf("%d", ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}