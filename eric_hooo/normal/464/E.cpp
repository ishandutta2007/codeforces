#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int mod = 1000000007;
const int P = 323232323;
const int N = 100020;

int MOD(long long x) {return x - x / mod * mod;}

int pw[100050];

int power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? MOD(1ll * MOD(tmp * tmp) * a) : MOD(tmp * tmp);
}

struct Segment_tree {
	struct Node {
		int hash, lson, rson;
		Node () {}
		Node (int h, int l = -1, int r = -1) {hash = h, lson = l, rson = r;}
	}T[50000000];
	int tot;
	void init() {tot = 0;}
	void pushup(int now, int l, int r) {
		int ll = T[now].lson, rr = T[now].rson;
		int mid = l + r >> 1;
		T[now].hash = MOD(1ll * T[ll].hash * pw[r - mid] + T[rr].hash);
	}
	int Build(int l, int r) {
		if (l == r) {
			T[tot++] = Node (0);
			return tot - 1;
		}
		int mid = l + r >> 1, now = tot++;
		T[now].lson = Build(l, mid), T[now].rson = Build(mid + 1, r);
		pushup(now, l, r);
		return now;
	}
	int Update(int now, int l, int r, int pos) { 
		if (l == r) {
			int cur = tot++;
			T[cur] = T[now];
			T[cur].hash ^= 1;
			return cur;
		}
		int mid = l + r >> 1, cur = tot++;
		T[cur] = T[now];
		if (pos <= mid) T[cur].lson = Update(T[now].lson, l, mid, pos);
		else T[cur].rson = Update(T[now].rson, mid + 1, r, pos);
		pushup(cur, l, r);
		return cur;
	}
	int Query(int now, int l, int r, int pos) {
		if (l == r) return T[now].hash;
		int mid = l + r >> 1;
		if (pos <= mid) return Query(T[now].lson, l, mid, pos);
		return Query(T[now].rson, mid + 1, r, pos);
	}
	bool cmp(int a, int b, int l, int r) {
		if (l == r) return T[a].hash > T[b].hash;
		if (T[a].hash == T[b].hash) return 0;
		int mid = l + r >> 1;
		if (T[T[a].rson].hash == T[T[b].rson].hash) return cmp(T[a].lson, T[b].lson, l, mid);
		return cmp(T[a].rson, T[b].rson, mid + 1, r);
	}
	int add(int now, int pos) {
		while (Query(now, 0, N, pos)) now = Update(now, 0, N, pos), pos++;
		now = Update(now, 0, N, pos);
		return now;
	}
	int get_val(int now, int l, int r) {
		if (l == r) return T[now].hash ? power(2, l) : 0;
		int mid = l + r >> 1;
		return MOD(get_val(T[now].lson, l, mid) + get_val(T[now].rson, mid + 1, r));
	}
}seg;

struct Point {
	int r, id;
	Point () {}
	Point (int a, int b) {r = a, id = b;}
	bool operator < (const Point &A) const {return seg.cmp(r, A.r, 0, N);}
};

int null;
vector <pii> from[100010];
int dist[100010], last[100010];
priority_queue <Point> q;

void Dij(int s) {
	memset(dist, -1, sizeof(dist));
	dist[s] = null; q.push(Point(dist[s], s));
	while (!q.empty()) {
		Point t = q.top(); q.pop();
		int x = t.id;
//		cout << "x:" << x << endl;
		if (seg.T[t.r].hash != seg.T[dist[x]].hash) continue;
		for (int i = 0; i < from[x].size(); i++) { 
			int v = from[x][i].fi, w = from[x][i].se;
//			cout << "  v:" << v << endl;
//			cout << "    dist:" << seg.get_val(dist[x], 0, N) << endl;
			int tmp = seg.add(dist[x], w);
//			cout << "    nval:" << seg.get_val(tmp, 0, N) << endl;
//			cout << "    seg:" << seg.cmp(dist[v], tmp, 0, N) << endl;
			if (dist[v] == -1 || seg.cmp(dist[v], tmp, 0, N)) {
				dist[v] = tmp, last[v] = x;
				q.push(Point(tmp, v));
			}
		}
	}
}

int main() {
	pw[0] = 1;
	for (int i = 1; i <= N; i++) {
		pw[i] = MOD(1ll * pw[i - 1] * P);
	}
	seg.init(), null = seg.Build(0, N);
	int TTT = seg.add(null, 0);
	TTT = seg.add(TTT, 0);
	int AAA = seg.add(null, 2);
	AAA = seg.add(AAA, 0);
//	cout << "  cmp:" << seg.cmp(AAA, TTT, 0, N) << endl;
//	cout << seg.get_val(TTT, 0, N) << endl;
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		from[u].push_back(mp(v, c));
		from[v].push_back(mp(u, c));
	}
	int S, T; scanf("%d%d", &S, &T);
	Dij(S);
	if (dist[T] == -1) {
		printf("-1\n");
		return 0;
	}
//	cout << seg.get_val(dist[3], 0, N) << endl;
	printf("%d\n", seg.get_val(dist[T], 0, N));
	vector <int> v;
	while (T != S) v.push_back(T), T = last[T];
	v.push_back(S);
	printf("%d\n", v.size());
	for (int i = v.size() - 1; i >= 0; i--) {
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}