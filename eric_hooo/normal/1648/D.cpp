#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <long long, int> pli;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
long long pre[500010], suc[500010];
long long a[500010], S[500010];
vector <pii> G[500010];
long long ans[500010];
long long dist[500010];
long long lef[500010], rig[500010];
priority_queue <pli> q;

void Solve(int l, int r) {
	if (l == r) {
		return ;
	}
	int mid = l + r >> 1;
	for (int i = mid + 1; i <= r; i++) {
		dist[i] = -INF;
	}
	for (int i = l; i <= mid; i++) {
		dist[i] = pre[i] - S[i - 1], q.push(mp(dist[i], i));
	}
	while (!q.empty()) {
		pli tmp = q.top(); q.pop();
		int x = tmp.se;
		if (tmp.fi != dist[x]) continue;
		auto Flush = [&](int v, long long w) -> void {
			if (dist[v] < dist[x] + w) {
				dist[v] = dist[x] + w;
				q.push(mp(dist[v], v));
			}
		};
		if (x > l) Flush(x - 1, 0);
		else {
			for (int i = l; i <= r; i++) {
				Flush(i, -lef[i]);
			}
		}
		for (auto it : G[x]) {
			Flush(it.fi, -it.se);
		}
		Flush(r, -rig[x]);
	}
	for (int i = mid + 1; i <= r; i++) {
		ans[i] = max(ans[i], dist[i]);
	}
	for (int i = mid + 1; i <= r; i++) {
		lef[mid] = min(lef[mid], lef[i]);
	}
	for (int i = l; i <= mid; i++) {
		rig[mid + 1] = min(rig[mid + 1], rig[i]);
	}
	for (int i = l; i <= mid; i++) {
		while (G[i].size()) {
			int j = G[i].back().fi; long long w = G[i].back().se;
			if (j <= mid) break;
			G[i].pop_back();
			lef[j] = min(lef[j], w);
			rig[i] = min(rig[i], w);
		}
	}
	Solve(l, mid), Solve(mid + 1, r);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &pre[i]);
		pre[i] += pre[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		S[i] = S[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &suc[i]);
	}
	for (int i = n; i >= 1; i--) {
		suc[i] += suc[i + 1];
	}
	for (int i = 1; i <= m; i++) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		r++;
		G[l].push_back(mp(r, k));
	}
	for (int i = 1; i <= n + 1; i++) {
		sort(G[i].begin(), G[i].end());
	}
	for (int i = 1; i <= n + 1; i++) {
		ans[i] = -INF, lef[i] = rig[i] = INF;
	}
	Solve(1, n + 1);
	long long ans = -INF;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, :: ans[i + 1] + suc[i] + S[i]);
	}
	printf("%lld\n", ans);
	return 0;
}