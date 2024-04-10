#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 200005;
struct Edge { int v, w; };
struct Node {
	int u, a, b;
	LL d;
	bool operator<(const Node &o) const { return d > o.d; }
};
LL dis[MAXN][2][2];
int n, m;
vector<Edge> gra[MAXN];
priority_queue<Node> pq;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		gra[u].push_back(Edge { v, w });
		gra[v].push_back(Edge { u, w });
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[1][0][0] = 0;
	pq.push(Node { 1, 0, 0, 0ll });
	while (!pq.empty()) {
		Node d = pq.top(); pq.pop();
		if (dis[d.u][d.a][d.b] != d.d) continue;
		for (const Edge &e : gra[d.u]) {
			LL &t = dis[e.v][d.a][d.b];
			if (t > e.w + d.d) {
				t = e.w + d.d;
				pq.push(Node { e.v, d.a, d.b, t });
			}
			if (!d.a) {
				LL &t1 = dis[e.v][1][d.b];
				if (t1 > d.d) {
					t1 = d.d;
					pq.push(Node { e.v, 1, d.b, t1 });
				}
			}
			if (!d.b) {
				LL &t2 = dis[e.v][d.a][1];
				if (t2 > e.w * 2 + d.d) {
					t2 = e.w * 2 + d.d;
					pq.push(Node { e.v, d.a, 1, t2 });
				}
			}
			if (!d.a && !d.b) {
				LL &t3 = dis[e.v][1][1];
				if (t3 > e.w + d.d) {
					t3 = e.w + d.d;
					pq.push(Node { e.v, 1, 1, t3 });
				}
			}
		}
	}
	for (int i = 2; i <= n; i++)
		printf("%lld ", dis[i][1][1]);
	return 0;
}