#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(v) ;
#define eprintf(...) if(0) fprintf(stderr, "...")
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }

template<int maxN, int maxM>
struct Dinic {
	int n, m, s, t;
	struct Edge {
		int from, to, last;
		LL flow, cap;
		Edge() {}
		Edge(int f, int t, int l, LL fl, LL cp) :
			from(f), to(t), last(l), flow(fl), cap(cp) {}
	} edges[maxM << 1]; int h[maxN];
	void init(int n) {
		this->n = n;
		m = 1;
		for(int u = 0; u <= n; ++u) h[u] = 0;
	}
	void link(int x, int y, LL z) {
//		eprintf("link %d %d %lld\n", x, y, z);
		edges[++m] = Edge(x, y, h[x], 0, z); h[x] = m;
		edges[++m] = Edge(y, x, h[y], 0, 0); h[y] = m;
	}
	int cur[maxN], d[maxN];
	bool BFS() {
		for(int u = 0; u <= n; ++u) d[u] = 0x3f3f3f3f;
		queue<int> Q; Q.push(s); d[s] = 1;
		while(Q.size()) {
			int u = Q.front(); Q.pop();
			for(int i = h[u]; i; i = edges[i].last) {
				const Edge &e = edges[i];
				if(e.cap > e.flow && d[e.to] == 0x3f3f3f3f) {
					d[e.to] = d[u] + 1;
					Q.push(e.to);
				}
			}
		}
		return d[t] != 0x3f3f3f3f;
	}
	LL DFS(int u, LL a) {
		if(u == t || a == 0) return a;
		LL flow = 0, f;
		for(int &i = cur[u]; i; i = edges[i].last) {
			const Edge &e = edges[i];
			if(d[e.to] == d[u] + 1 && (f = DFS(e.to, std::min(a, e.cap - e.flow))) > 0) {
				flow += f; a -= f;
				edges[i].flow += f;
				edges[i ^ 1].flow -= f;
			}
			if(a == 0) break;
		}
		return flow;
	}
	LL maxflow(int s, int t) {
		this->s = s; this->t = t;
		LL flow = 0;
		while(BFS()) {
			for(int u = 0; u <= n; ++u) cur[u] = h[u];
			flow += DFS(s, 0x3f3f3f3f3f3f3f3fLL);
		}
		return flow;
	}
};

const int maxN = 50 + 5;
const int INF = 0x3f3f3f3f;
int n;
int a[maxN], b[maxN], c[maxN], d[maxN];

Dinic<maxN * 20, maxN * maxN * 50> dinic;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
//	for(int i = 1; i <= n; ++i) {
//		a[i] = 5 * i + 1; c[i] = 5 * i + 6;
//		b[i] = 5 * i + 1; d[i] = 5 * i + 6;
//	}
	vector<int> x(1, 1), y(1, 1);
	for(int i = 1; i <= n; ++i) {
		c[i]++; d[i]++;
		x.push_back(a[i]); x.push_back(c[i]);
		y.push_back(b[i]); y.push_back(d[i]);
	}
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	sort(y.begin(), y.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	int xn = x.size(), yn = y.size();
//	display(xn + yn + 2 + n * 2);
	dinic.init(xn + yn + 2 + n * 2);
	int S = xn + yn + 1, T = xn + yn + 2;
	for(int i = 1; i < xn; ++i) dinic.link(S, i, x[i] - x[i - 1]);
	for(int i = 1; i < yn; ++i) dinic.link(xn + i, T, y[i] - y[i - 1]);
	int cnt = xn + yn + 2;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < xn; ++j) if(a[i] <= x[j - 1] && x[j] <= c[i])
			dinic.link(j, cnt + 1, INF);
		for(int j = 1; j < yn; ++j) if(b[i] <= y[j - 1] && y[j] <= d[i])
			dinic.link(cnt + 2, j + xn, INF);
		dinic.link(cnt + 1, cnt + 2, INF);
		cnt += 2;
		display(cnt);
	}
//	display(cnt); display(dinic.m);
	cout << dinic.maxflow(S, T) << endl;
	return 0;
}