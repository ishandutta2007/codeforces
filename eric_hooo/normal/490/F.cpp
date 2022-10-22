#include <bits/stdc++.h>
using namespace std;

int dp[6010];
vector <int> from[6010];
int a[6010], tmp[6010];

struct Segment_tree {
	int maxj[24010];
	void Build() {memset(maxj, 0, sizeof(maxj));}
	void Update(int now, int l, int r, int pos, int val) {
		if (l == r) {
			maxj[now] = val;
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, val);
		else Update(now << 1 | 1, mid + 1, r, pos, val);
		maxj[now] = max(maxj[now << 1], maxj[now << 1 | 1]);
	}
	int Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return maxj[now];
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return max(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg;

int id[6010], size[6010];
int cnt;

void dfs(int x, int last) {
	id[x] = cnt++, size[x] = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dfs(v, x), size[x] += size[v];
	}
}

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int main () {
	int n; scanf("%d", &n);
	vector <int> order;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		order.push_back(i);
	}
	sort(order.begin(), order.end(), cmp);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		seg.Build();
		cnt = 1, dfs(i, i);
		for (int j = 0; j < order.size(); ) {
			int nxt = j;
			while (nxt < order.size() && a[order[nxt]] == a[order[j]]) nxt++;
			for (int k = j; k < nxt; k++) {
				tmp[k] = seg.Query(1, 1, n, id[order[k]], id[order[k]] + size[order[k]] - 1) + 1;
				if (order[k] == i) {
					ans = max(ans, tmp[k]);
					goto OUT;
				}
			}
			for (int k = j; k < nxt; k++) {
				seg.Update(1, 1, n, id[order[k]], tmp[k]);
			}
			j = nxt;
		}
		OUT:;
	}
	printf("%d\n", ans);
	return 0;
}