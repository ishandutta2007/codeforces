/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 301010
#define MOD 100000009
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

struct node {
	ll ls, rs, sz;
	ll sum;
	node() {}
	node(ll ls, ll rs, ll sz, ll sum) :ls(ls), rs(rs), sz(sz), sum(sum) {}
};

node operator+(const node& n1, const node& n2) {
	node ret;
	ret.sum = n1.sum + n2.sum;
	ret.sum += n1.rs * n2.ls;
	ret.ls = n1.ls;
	if (n1.sz == n1.ls) ret.ls += n2.ls;
	ret.rs = n2.rs;
	if (n2.sz == n2.rs) ret.rs += n1.rs;
	ret.sz = n1.sz + n2.sz;
	return ret;
}

template <typename T>
class Segment_Tree {
	//0-based index Segment Tree
	//O(N), O(lgN)
private:
	unsigned int N, s;
	vector<T> tree;
	vector<unsigned int> l, r;
	T query(unsigned int low, unsigned int high, unsigned int loc) {
		if (low == l[loc] && high == r[loc]) return tree[loc];
		if (high <= r[loc * 2]) return query(low, high, loc * 2);
		if (low >= l[loc * 2 + 1]) return query(low, high, loc * 2 + 1);
		return query(low, r[loc * 2], loc * 2) + query(l[loc * 2 + 1], high, loc * 2 + 1);
	}
	void _update(unsigned int loc, T val) {
		loc += s;
		tree[loc] = val;
		loc /= 2;
		while (loc) {
			tree[loc] = tree[loc * 2] + tree[loc * 2 + 1];
			loc /= 2;
		}
	}
	void init(unsigned int x = 1) {
		if (x >= s) {
			l[x] = r[x] = x - s;
			return;
		}
		init(x * 2);
		init(x * 2 + 1);
		l[x] = l[x * 2];
		r[x] = r[x * 2 + 1];
		tree[x] = tree[x * 2] + tree[x * 2 + 1];
	}
public:
	Segment_Tree<T>() {

	}
	Segment_Tree<T>(vector<T>& v) {
		N = v.size();
		s = 1 << (unsigned int)ceil(log2(N));
		tree.resize(2 * s + 1);
		l.resize(2 * s + 1);
		r.resize(2 * s + 1);
		unsigned int i;
		for (i = 0; i < N; i++) tree[i + s] = v[i];
		init();
	}
	T query(unsigned int low, unsigned int high) { return query(low, high, 1); }
	void update(unsigned int location, T new_value) { _update(location, new_value); }
};

ll arr[MAX];
ll sub[MAX];

void solve() {
	ll N;
	cin >> N;
	ll i;
	ll Q;
	cin >> Q;
	vector<node> v;
	//v.push_back(node(0, 0, 0));
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
		sub[i - 1] = arr[i] - arr[i - 1];
		if (sub[i - 1] >= 0) v.push_back(node(1, 1, 1, 1));
		else v.push_back(node(0, 0, 1, 0));
	}
	Segment_Tree<node> segtree(v);
	ll a, b, c;
	for (i = 1; i <= Q; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b] = c;
			sub[b] = arr[b + 1] - arr[b];
			sub[b - 1] = arr[b] - arr[b - 1];
			if (sub[b - 1] >= 0) segtree.update(b - 1, node(1, 1, 1, 1));
			else segtree.update(b - 1, node(0, 0, 1, 0));
			if (b != N) {
				if (sub[b] >= 0) segtree.update(b, node(1, 1, 1, 1));
				else segtree.update(b, node(0, 0, 1, 0));
			}
		}
		else {
			if (b == c) cout << 1 << ln;
			else cout << segtree.query(b, c - 1).sum + (c - b + 1) << ln;
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