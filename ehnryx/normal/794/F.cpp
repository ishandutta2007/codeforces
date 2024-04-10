//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N =	1<<17;
const int M = 10;
ll st[2*N][M];
int to[2*N][M];
bool z[2*N];

void reset(int i) {
	for(int d=0; d<M; d++) {
		to[i][d] = d;
	}
}

void pull(int i) {
	for(int d=0; d<M; d++) {
		st[i][d] = st[2*i][d] + st[2*i+1][d];
	}
}

void build() {
	for(int i=1; i<2*N; i++) {
		reset(i);
	}
	for(int i=N-1; i>0; i--) {
		pull(i);
	}
}

void push(int i) {
	if(z[i]) {
		vector<ll> left(M), right(M);
		for(int d=0; d<M; d++) {
			left[to[i][d]] += st[2*i][d];
			right[to[i][d]] += st[2*i+1][d];
			to[2*i][d] = to[i][to[2*i][d]];
			to[2*i+1][d] = to[i][to[2*i+1][d]];
		}
		for(int d=0; d<M; d++) {
			st[2*i][d] = left[d];
			st[2*i+1][d] = right[d];
		}
		z[2*i] = z[2*i+1] = true;
		z[i] = false;
		reset(i);
	}
}

void update(int l, int r, int x, int y, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) {
		ll move = st[i][x];
		st[i][x] -= move;
		st[i][y] += move;
		for(int d=0; d<M; d++) {
			if(to[i][d] == x) {
				to[i][d] = y;
			}
		}
		z[i] = true;
		return;
	}
	push(i);
	int m = (s+e) / 2;
	update(l, r, x, y, 2*i, s, m);
	update(l, r, x, y, 2*i+1, m+1, e);
	pull(i);
}

ll query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return 0;
	if(l<=s && e<=r) {
		ll res = 0;
		for(int d=0; d<M; d++) {
			res += d * st[i][d];
		}
		return res;
	}
	push(i);
	int m = (s+e) / 2;
	return query(l,r,2*i,s,m) + query(l,r,2*i+1,m+1,e);
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		int v;
		cin >> v;
		for(int t=1; v>0; t*=M, v/=M) {
			st[i+N][v%M] += t;
		}
	}
	build();

	for(int i=0; i<m; i++) {
		int t;
		cin >> t;
		if(t == 1) {
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			update(l, r, x, y);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << nl;
		}
	}

	return 0;
}