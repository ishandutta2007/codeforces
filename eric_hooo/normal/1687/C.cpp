#include <bits/stdc++.h>
using namespace std;

long long a[200010], b[200010], c[200010];
int L[200010], R[200010], cnt[200010];
set <int> S[3];
int fa[200010];
int vis[200010];
vector <int> G[200010];

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

void merge(int x, int y) {fa[find(x)] = find(y);}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++) {
			G[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			a[i] += a[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &b[i]);
			b[i] += b[i - 1];
		}
		for (int i = 0; i <= n; i++) {
			c[i] = a[i] - b[i];
		}
		S[0].clear(), S[1].clear(), S[2].clear();
		for (int i = 0; i < m; i++) {
			int l, r; scanf("%d%d", &l, &r);
			l--;
			L[i] = l, R[i] = r;
			G[l].push_back(i), G[r].push_back(i);
			S[0].insert(i), cnt[i] = 0;
		}
		for (int i = 0; i <= n; i++) {
			fa[i] = i, vis[i] = 0;
		}
		auto Add = [&](int x) -> void {
			vis[x] = 1;
			if (x > 0 && vis[x - 1]) merge(x - 1, x);
			if (x < n && vis[x + 1]) merge(x, x + 1);
			for (auto it : G[x]) {
				S[cnt[it]].erase(it);
				cnt[it]++;
				S[cnt[it]].insert(it);
			}
		};
		for (int i = 0; i <= n; i++) {
			if (c[i] == 0) Add(i);
		}
		while (S[2].size()) {
			int id = *S[2].begin(); S[2].erase(S[2].begin());
			int l = L[id], r = R[id];
			while (find(l) < r) {
				Add(find(l) + 1);
			}
		}
		if (find(0) == find(n)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		END:;
	}
	return 0;
}