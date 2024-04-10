/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

vector<int> radj[MAX];
int bias[MAX];
int deg[MAX];
int rdeg[MAX];
int minv[MAX];
int dist[MAX];
int vis[MAX];

struct segtree {
	int N, s;
	vector<pii> tree;
	vector<int> l, r;
	segtree() {}
	void init(int x = 1) {
		if (x >= s) {
			tree[x] = { 1010101, x - s + 1 };
			l[x] = r[x] = x - s + 1;
			return;
		}
		init(x * 2);
		init(x * 2 + 1);
		tree[x] = min(tree[x * 2], tree[x * 2 + 1]);
		l[x] = l[x * 2];
		r[x] = r[x * 2 + 1];
	}
	segtree(int N) :N(N) {
		s = 1 << (int)ceil(log2(N));
		l = r = vector<int>(2 * s + 1);
		tree.resize(2 * s + 1);
	}
	void update(int x, int v) {
		x += s - 1;
		tree[x].first = v;
		x /= 2;
		while (x) {
			tree[x] = min(tree[x * 2], tree[x * 2 + 1]);
			x >>= 1;
		}
	}
	pii query(int low, int high, int loc = 1) {
		if (low == l[loc] && high == r[loc]) return tree[loc];
		if (high <= r[loc * 2]) return query(low, high, loc * 2);
		if (low >= l[loc * 2 + 1]) return query(low, high, loc * 2 + 1);
		return min(query(low, r[loc * 2], loc * 2), query(l[loc * 2 + 1], high, loc * 2 + 1));
	}
};

void solve() {
	int N, M;
	cin >> N >> M;
	int i, a, b;
	vector<pii> edge;
	for (i = 1; i <= M; i++) {
		cin >> a >> b;
		radj[b].push_back(a);
		edge.push_back({ a, b });
		deg[a]++;
	}
	for (i = 1; i < N; i++) dist[i] = N + M + 10;
	segtree seg(N);
	seg.init();
	seg.update(N, 0);
	for (i = 1; i <= N; i++) minv[i] = 1010101;
	while (1) {
		auto q = seg.query(1, N);
		int x = q.second;
		seg.update(x, 1010101);
		if (vis[x]) continue;
		vis[x] = 1;
		if (x == 1) {
			cout << dist[x] << Ln;
			return;
		}
		for (auto v : radj[x]) {
			minv[v] = min(minv[v], dist[x] - bias[v]);
			bias[v]++;
			dist[v] = deg[v] + minv[v];
			seg.update(v, dist[v]);
		}
	}
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}