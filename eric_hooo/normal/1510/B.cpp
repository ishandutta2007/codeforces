#include <bits/stdc++.h>
using namespace std;

struct MCMF {
	int head[2100], nxt[200000], to[200000], w[200000], f[200000], TOT;
	int inq[2100], path[2100], edge[2100], dist[2100], n;
	queue <int> q;
	void init(int N) {n = N, TOT = 0; for (int i = 0; i < n; i++) head[i] = -1;}
	void add_edge(int x, int y, int W, int F) {
		to[TOT] = y, w[TOT] = W, f[TOT] = F, nxt[TOT] = head[x], head[x] = TOT++;
		to[TOT] = x, w[TOT] = 0, f[TOT] = -F, nxt[TOT] = head[y], head[y] = TOT++;
	}
	bool spfa(int S, int T) {
		for (int i = 0; i < n; i++) dist[i] = 0x3f3f3f3f; dist[S] = 0, q.push(S), inq[S] = 1;
		while (!q.empty()) {
			int x = q.front(); q.pop(), inq[x] = 0;
			for (int i = head[x]; ~i; i = nxt[i]) {
				int v = to[i];
				if (w[i] && dist[v] > dist[x] + f[i]) {
					dist[v] = dist[x] + f[i], path[v] = x, edge[v] = i;
					if (!inq[v]) q.push(v), inq[v] = 1;
				}
			}
		}
		return dist[T] != 0x3f3f3f3f;
	}
	void mcmf(int S, int T) {
		while (spfa(S, T)) {
			int flow = 0x3f3f3f3f, cur = T;
			while (cur != S) flow = min(flow, w[edge[cur]]), cur = path[cur];
			cur = T;
			while (cur != S) w[edge[cur]] -= flow, w[edge[cur] ^ 1] += flow, cur = path[cur]; 
		}
	}
}mcmf;

char buf[20];
int a[1100];
string op;
int n;

void GetOp(int x, int y) {
	cerr << "   x:" << x << " " << y << endl;
	assert((x & y) == x);
	for (int i = 0; i < n; i++) {
		if (!(x >> i & 1) && (y >> i & 1)) op.push_back('0' + i);
	}
}

int main() {
	int m; scanf("%d%d", &n, &m);
	int S = m + m, T = S + 1, ans = 0; mcmf.init(T + 1);
	for (int i = 0; i < m; i++) {
		scanf("%s", buf);
		int mask = 0, cnt = 0;
		for (int j = 0; j < n; j++) cnt += buf[j] == '1', mask |= (buf[j] == '1') << j; 
		a[i] = mask, ans += cnt, mcmf.add_edge(S, i, 1, -cnt), mcmf.add_edge(i + m, T, 1, 0);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i != j && (a[i] & a[j]) == a[i]) mcmf.add_edge(i, j + m, 1, 0);
		}
	}
	mcmf.mcmf(S, T);
	for (int i = 0; i < m; i++) {
		int cur = i;
		for (int j = mcmf.head[i + m]; ~j; j = mcmf.nxt[j]) {
			if ((j & 1) && mcmf.w[j] == 1) goto NXT;
		}
		GetOp(0, a[i]);
		while (1) {
			for (int j = mcmf.head[cur]; ~j; j = mcmf.nxt[j]) {
				if (!(j & 1) && mcmf.w[j] == 0) {
					GetOp(a[cur], a[mcmf.to[j] - m]), cur = mcmf.to[j] - m;
					goto END;
				}
			}
			break;
			END:;
		}
		op.push_back('R');
		NXT:;
	}
	op.pop_back();
	printf("%d\n", (int)op.size());
	for (int i = 0; i < op.size(); i++) printf("%c ", op[i]); printf("\n");
	return 0;
}