#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 500000;
vector<pi64> e[maxn];
int lc[maxn], rc[maxn];
int vc = 0;

void addEdge(int v, int u, bool rev = false, i64 cost = 0) {
	if (rev) swap(v, u);
	e[v].pb(mp(u, cost));
}

int buildTree(int L, int R, bool down, vi &leaves) {
	int v = vc++;
	if (R - L == 1) {
		leaves[L] = v;
	} else {
		int M = (L + R) / 2;
		addEdge(v, lc[v] = buildTree(L, M, down, leaves), !down);
		addEdge(v, rc[v] = buildTree(M, R, down, leaves), !down);
	}
	return v;
}

void addSegEdges(int v, int L, int R, int lq, int rq, bool rev, int from, int w) {
	if (max(L, lq) >= min(R, rq)) return;
	if (lq <= L && R <= rq) {
		addEdge(from, v, rev, w);
		return;
	}
	int M = (L + R) / 2;
	addSegEdges(lc[v], L, M, lq, rq, rev, from, w);
	addSegEdges(rc[v], M, R, lq, rq, rev, from, w);
}

i64 dist[maxn];

int main() {
#ifdef LOCAL_DEFINE
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif

	int n, q, s;
	cin >> n >> q >> s;
	--s;

	vi ld(n), lu(n);
	int rd = buildTree(0, n, true, ld);
	int ru = buildTree(0, n, false, lu);
	forn(i, n) forn(j, 2) addEdge(ld[i], lu[i], j);

	forn(i, q) {
		int t;
		cin >> t;
		if (t == 1) {
			int v, u, w;
			cin >> v >> u >> w;
			--v; --u;
			addEdge(ld[v], ld[u], false, w);
		} else {
			int v, l, r, w;
			cin >> v >> l >> r >> w;
			--v; --l;
			if (t == 2) addSegEdges(rd, 0, n, l, r, false, ld[v], w);
			else addSegEdges(ru, 0, n, l, r, true, ld[v], w);
		}
	}

	priority_queue<pi64> qq;
	forn(i, vc) dist[i] = 1e18;
	dist[ld[s]] = 0;
	qq.push(mp(0, ld[s]));
	while (!qq.empty()) {
		auto w = qq.top();
		qq.pop();
		int v = w.se;
		i64 dd = -w.fi;
		if (dd != dist[v]) continue;
		for (auto ww: e[v]) {
			int u = ww.fi;
			i64 ncost = dd + ww.se;
			if (uin(dist[u], ncost)) {
				qq.push({-dist[u], u});
			}
		}
	}

	forn(i, n) {
		int v = ld[i];
		if (dist[v] > 1e17) cout << -1 << ' ';
		else cout << dist[v] << ' ';
	}
	cout << '\n';

#ifdef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}