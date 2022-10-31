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

#define MAX 251010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "Yes"
#define no "No"

int arr[MAX];
int up[MAX];
int down[MAX];
int dist[MAX];

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
		init();
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
		if (low > high) return pii(1010101, 0);
		if (low == l[loc] && high == r[loc]) return tree[loc];
		if (high <= r[loc * 2]) return query(low, high, loc * 2);
		if (low >= l[loc * 2 + 1]) return query(low, high, loc * 2 + 1);
		return min(query(low, r[loc * 2], loc * 2), query(l[loc * 2 + 1], high, loc * 2 + 1));
	}
};

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) cin >> arr[i], dist[i] = 0, up[i] = down[i] = 0;
	vector<int> uv, dv;
	uv.push_back(N);
	dv.push_back(N);
	for (i = N - 1; i >= 1; i--) {
		while (uv.size() && arr[uv.back()] < arr[i]) uv.pop_back();
		while (dv.size() && arr[dv.back()] > arr[i]) dv.pop_back();
		uv.push_back(i);
		dv.push_back(i);
		if (uv.size()) up[i] = uv.back();
		if (dv.size()) down[i] = dv.back();
	}
	uv.clear();
	dv.clear();
	segtree upseg(N), downseg(N);
	upseg.update(N, 0);
	downseg.update(N, 0);
	uv.push_back(N);
	dv.push_back(N);
	for (i = N - 1; i >= 1; i--) {
		while (uv.size() && arr[uv.back()] < arr[i]) upseg.update(uv.back(), N), uv.pop_back();
		while (dv.size() && arr[dv.back()] > arr[i]) downseg.update(dv.back(), N), dv.pop_back();
		int ui, di;
		ui = di = N;
		if (uv.size()) ui = uv.back();
		if (dv.size()) di = dv.back();
		dist[i] = N;
		dist[i] = min(dist[i], upseg.query(i, di).first + 1);
		dist[i] = min(dist[i], downseg.query(i, ui).first + 1);
		upseg.update(i, dist[i]);
		downseg.update(i, dist[i]);
		uv.push_back(i);
		dv.push_back(i);
	}
	cout << dist[1] << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}