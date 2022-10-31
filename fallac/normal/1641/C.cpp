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
typedef pair<int, int> pi;

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

int l[528080], r[528080];

struct rmq {
	int tree[528000];
	int N, s;
	void init(int x = 1) {
		if (x >= s) {
			l[x] = r[x] = x - s + 1;
			return;
		}
		init(x * 2);
		init(x * 2 + 1);
		l[x] = l[x * 2];
		r[x] = r[x * 2 + 1];
		tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
	}
	rmq() {}
	rmq(int N) :N(N) {
		s = 1 << (int)ceil(log2(N));
	}
	void update(int x, int a) {
		x += s - 1;
		tree[x] = a;
		x /= 2;
		while (x) {
			tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
			x /= 2;
		}
	}
	int query(int low, int high, int loc = 1) {
		if (l[loc] == low && r[loc] == high) return tree[loc];
		if (high <= r[loc * 2]) return query(low, high, loc * 2);
		if (low >= l[loc * 2 + 1]) return query(low, high, loc * 2 + 1);
		return max(query(low, r[loc * 2], loc * 2), query(l[loc * 2 + 1], high, loc * 2 + 1));
	}
};

struct dsu {
	int p[MAX];
	int mn[MAX];
	int mx[MAX];
	dsu(int N) {
		int i;
		for (i = 1; i <= N; i++) p[i] = i, mn[i] = mx[i] = i;
	}
	int find(int x) {
		if (p[x] == x) return x;
		return p[x] = find(p[x]);
	}
	void uni(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		p[a] = b;
		mn[b] = min(mn[a], mn[b]);
		mx[b] = max(mx[a], mx[b]);
	}
};

int iarr[MAX];
int sl[MAX];
int sr[MAX]; //streak
int chk[MAX];

void solve() {
	int N, Q;
	cin >> N >> Q;
	int q;
	int t, l, r, x, i, j;
	set<int> st;
	for (i = 1; i <= N; i++) st.insert(i);
	rmq intv(N), allv(N);
	for (i = 1; i <= N; i++) allv.tree[intv.s + i - 1] = 1, intv.tree[intv.s + i - 1] = -10 * N, iarr[i] = N * 10;
	for (i = 1; i <= N; i++) sl[i] = sr[i] = i, chk[i] = 1;
	intv.init();
	allv.init();
	chk[0] = 1;
	chk[N + 1] = 1;
	dsu d(N);
	for (q = 1; q <= Q; q++) {
		cin >> t;
		if (t == 0) {
			cin >> l >> r >> x;
			if (x == 1) {
				if (iarr[l] <= r) continue;
				iarr[l] = r;
				intv.update(l, -r);
			}
			else {
				vector<int> rem;
				auto it = st.lower_bound(l);
				while (it != st.end() && *it <= r) {
					rem.push_back(*it);
					it++;
					if (it == st.end()) break;
				}
				for (auto r : rem) {
					st.erase(r), allv.update(r, 0);
					chk[r] = 0;
					if (!chk[r - 1] && r > 1) d.uni(r - 1, r);
					if (r < N && !chk[r + 1]) d.uni(r, r + 1);
				}
			}
		}
		else {
			cin >> j;
			if (!chk[j]) {
				cout << "NO" << ln;
				continue;
			}
			int il;
			if (j == 1 || chk[j - 1]) il = j;
			else il = d.mn[d.find(j - 1)];
			int ir;
			if (j == N || chk[j + 1]) ir = j;
			else ir = d.mx[d.find(j + 1)];
			if (-intv.query(il, ir) <= ir) cout << yes << Ln;
			else cout << "N/A" << ln;
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