#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 100005;
vector<int> vec[MAXN];
int cnt[MAXN], ans[MAXN], n, m, T;

int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) cnt[i] = 0;
		for (int i = 1; i <= m; i++) {
			vec[i].clear();
			int k; scanf("%d", &k);
			for (int j = 1; j <= k; j++) {
				int t; scanf("%d", &t);
				vec[i].push_back(t);
			}
			++cnt[vec[i][0]];
		}
		int p = 0;
		for (int i = 1; i <= n; i++)
			if (cnt[i] > (m + 1) / 2) p = i;
		if (!p) {
			puts("YES");
			for (int i = 1; i <= m; i++) printf("%d ", vec[i][0]);
			puts("");
		} else {
			int c = cnt[p] - (m + 1) / 2;
			for (int i = 1; i <= m; i++) if (c > 0 && vec[i][0] == p && (int)vec[i].size() > 1) {
				--c; ans[i] = vec[i][1];
			} else ans[i] = vec[i][0];
			if (c > 0) puts("NO");
			else {
				puts("YES");
				for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
				puts("");
			}
		}
	}
	return 0;
}