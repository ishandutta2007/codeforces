#include <bits/stdc++.h>
using namespace std;

namespace Graph {
	int N, TOT;
	int head[8000000], to[20000000], nxt[20000000];
	void AddEdge(int x, int y, int w) {
		if (!x || !y) return ;
		to[TOT] = y << 1 | w, nxt[TOT] = head[x], head[x] = TOT++;
	}
	void Init(int n) {
		N = n, TOT = 0;
		for (int i = 1; i <= N; i++) {
			head[i] = -1;
		}
	}
	int NewNode() {head[++N] = -1; return N;}
	int dist[8000000], vis[8000000];
	deque <int> q;
	int Solve(int a, int b) {
		for (int i = 1; i <= N; i++) {
			dist[i] = 0x3f3f3f3f, vis[i] = 0;
		}
		q.push_back(a), dist[a] = 0;
		while (!q.empty()) {
			int x = q.front(); q.pop_front();
			if (vis[x]) continue;
			vis[x] = 1;
			for (int e = head[x]; ~e; e = nxt[e]) {
				int v = to[e] >> 1, w = to[e] & 1;
				if (dist[v] > dist[x] + w) {
					dist[v] = dist[x] + w;
					w ? q.push_back(v) : q.push_front(v);
				}
			}
		}
		return dist[b];
	}
}

using Graph :: NewNode;
using Graph :: AddEdge;

namespace SEG {
	int Tdw[1 << 19], Tup[1 << 19];
	void Build(int now, int l, int r) {
		Tdw[now] = Tup[now] = 0;
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void Update(int now, int l, int r, int pos) {
		if (l == r) {
			AddEdge(Tdw[now] = NewNode(), pos, 1);
			AddEdge(pos, Tup[now] = NewNode(), 1);
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos);
		else Update(now << 1 | 1, mid + 1, r, pos);
		AddEdge(Tdw[now] = NewNode(), Tdw[now << 1], 0), AddEdge(Tdw[now], Tdw[now << 1 | 1], 0);
		AddEdge(Tup[now << 1], Tup[now] = NewNode(), 0), AddEdge(Tup[now << 1 | 1], Tup[now], 0);
	}
	void Query(int now, int l, int r, int L, int R, int id) {
		if (l == L && r == R) {
			AddEdge(id, Tdw[now], 0);
			AddEdge(Tup[now], id, 0);
			return ;
		}
		int mid = l + r >> 1;
		if (R <= mid) Query(now << 1, l, mid, L, R, id);
		else if (L > mid) Query(now << 1 | 1, mid + 1, r, L, R, id);
		else Query(now << 1, l, mid, L, mid, id), Query(now << 1 | 1, mid + 1, r, mid + 1, R, id);
	}
}

int a[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, A, B; scanf("%d%d%d", &n, &A, &B);
		static vector <int> all[200010];
		for (int i = 1; i <= n; i++) {
			all[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			all[a[i]].push_back(i);
		}
		Graph :: Init(n);
		SEG :: Build(1, 1, n);
		for (int i = n; i >= 1; i--) {
			for (auto x : all[i]) {
				SEG :: Query(1, 1, n, max(1, x - i), min(n, x + i), x);
				SEG :: Update(1, 1, n, x);
			}
		}
		printf("%d\n", Graph :: Solve(A, B));
	}
	return 0;
}