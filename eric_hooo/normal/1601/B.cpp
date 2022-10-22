#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n;
int a[300010], b[300010];
vector <pii> G[2000010];
int dist[2000010], lst[2000010];
priority_queue <pii, vector <pii>, greater <pii> > q;
int qwq[2000010];

void Dij() {
	memset(dist, 0x3f, sizeof(dist)), dist[n] = 0, q.push(mp(dist[n], n));
	while (!q.empty()) {
		pii t = q.top(); q.pop();
		int x = t.se;
		if (dist[x] != t.fi) continue;
		for (auto it : G[x]) {
			int v = it.fi, w = it.se;
			if (dist[v] > dist[x] + w) {
				dist[v] = dist[x] + w, lst[v] = x;
				q.push(mp(dist[v], v));
			}
		}
	}
}

int ID(int x) {
	return n + x;
}

void Build(int now, int l, int r) {
	if (l == r) {
		G[ID(now)].push_back(mp(l + b[l], 0));
		qwq[ID(now)] = l;
		return ;
	}
	G[ID(now)].push_back(mp(ID(now << 1), 0));
	G[ID(now)].push_back(mp(ID(now << 1 | 1), 0));
	int mid = l + r >> 1;
	Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
}

void AddEdge(int now, int l, int r, int L, int R, int rt) {
	if (l == L && r == R) {
		G[rt].push_back(mp(ID(now), 1));
		return ;
	}
	int mid = l + r >> 1;
	if (R <= mid) AddEdge(now << 1, l, mid, L, R, rt);
	else if (L > mid) AddEdge(now << 1 | 1, mid + 1, r, L, R, rt);
	else AddEdge(now << 1, l, mid, L, mid, rt), AddEdge(now << 1 | 1, mid + 1, r, mid + 1, R, rt);
}

int main() {
	memset(qwq, -1, sizeof(qwq));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	Build(1, 0, n);
	for (int i = 1; i <= n; i++) {
		AddEdge(1, 0, n, i - a[i], i, i);
	}
	Dij();
	if (dist[0] == 0x3f3f3f3f) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", dist[0]);
	int cur = 0;
	vector <int> path;
	while (cur != n) {
		cur = lst[cur];
		if (qwq[cur] != -1) path.push_back(qwq[cur]);
	}
	reverse(path.begin(), path.end());
	for (auto it : path) {
		printf("%d ", it);
	}
	printf("\n");
	return 0;
}