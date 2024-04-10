#include <bits/stdc++.h>
using namespace std;

vector <int> G[1000010];
int a[1000010];
int n, q;
int ans[1000010];
int L[1000010], K[1000010];
vector <int> qry[1000010];
int cnt[1000010];
int T[1000010];
vector <int> num[1000010];

void modify(int x, int v) {
	while (x <= n + 1) T[x] += v, x += x & -x;
}

int query(int x) {
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

int GetKth(int k) {
	int x = 0, cur = 0;
	for (int i = 19; i >= 0; i--) {
		int nx = x | 1 << i;
		if (nx <= n && cur + T[nx] < k) cur += T[nx], x = nx;
	}
	x++;
	if (query(x) < k) return -1;
	int id = num[x].back();
	while (cnt[id] != x) num[x].pop_back(), id = num[x].back();
	return id;
}

void dfs(int x, int last) {
	modify(cnt[a[x]], -1), cnt[a[x]]++, modify(cnt[a[x]], 1), num[cnt[a[x]]].push_back(a[x]);
	for (auto id : qry[x]) {
		int l = L[id], k = K[id];
		k += query(l);
		ans[id] = GetKth(k);
	}
	for (auto v : G[x]) if (v != last) {
		dfs(v, x);
	}
	modify(cnt[a[x]], -1), cnt[a[x]]--, modify(cnt[a[x]], 1), num[cnt[a[x]]].push_back(a[x]);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i++) {
			G[i].clear(), qry[i].clear(), cnt[i] = 1, num[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 2; i <= n; i++) {
			int x; scanf("%d", &x);
			G[x].push_back(i);
		}
		for (int i = 1; i <= q; i++) {
			int v, l, k; scanf("%d%d%d", &v, &l, &k);
			L[i] = l, K[i] = k;
			qry[v].push_back(i);
		}
		dfs(1, 1);
		for (int i = 1; i <= q; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}