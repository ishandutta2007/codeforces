#include<bits/stdc++.h>
using namespace std;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename U, typename V> struct pairnum {
	U u;
	V v;

	pairnum() : u(0), v(0) {}
	pairnum(long long val) : u(val), v(val) {}
	pairnum(const U& u_, const V& v_) : u(u_), v(v_) {}

	friend std::ostream& operator << (std::ostream& out, const pairnum& n) { return out << '(' << n.u << ',' << ' ' << n.v << ')'; }
	friend std::istream& operator >> (std::istream& in, pairnum& n) { long long val; in >> val; n = pairnum(val); return in; }

	friend bool operator == (const pairnum& a, const pairnum& b) { return a.u == b.u && a.v == b.v; }
	friend bool operator != (const pairnum& a, const pairnum& b) { return a.u != b.u || a.v != b.v; }

	pairnum inv() const {
		return pairnum(u.inv(), v.inv());
	}
	pairnum neg() const {
		return pairnum(u.neg(), v.neg());
	}
	pairnum operator- () const {
		return pairnum(-u, -v);
	}
	pairnum operator+ () const {
		return pairnum(+u, +v);
	}

	pairnum& operator ++ () {
		++u, ++v;
		return *this;
	}
	pairnum& operator -- () {
		--u, --v;
		return *this;
	}

	pairnum& operator += (const pairnum& o) {
		u += o.u;
		v += o.v;
		return *this;
	}
	pairnum& operator -= (const pairnum& o) {
		u -= o.u;
		v -= o.v;
		return *this;
	}
	pairnum& operator *= (const pairnum& o) {
		u *= o.u;
		v *= o.v;
		return *this;
	}
	pairnum& operator /= (const pairnum& o) {
		u /= o.u;
		v /= o.v;
		return *this;
	}

	friend pairnum operator ++ (pairnum& a, int) { pairnum r = a; ++a; return r; }
	friend pairnum operator -- (pairnum& a, int) { pairnum r = a; --a; return r; }
	friend pairnum operator + (const pairnum& a, const pairnum& b) { return pairnum(a) += b; }
	friend pairnum operator - (const pairnum& a, const pairnum& b) { return pairnum(a) -= b; }
	friend pairnum operator * (const pairnum& a, const pairnum& b) { return pairnum(a) *= b; }
	friend pairnum operator / (const pairnum& a, const pairnum& b) { return pairnum(a) /= b; }
};

using mnum = modnum<998244353>;
using hsh = pairnum<mnum, mnum>;

const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937 mt(FIXED_RANDOM);
const hsh BASE = hsh(mnum(mt()), mnum(mt()));

const int MAXN = 1.1e5;
hsh BASE_POW[MAXN];

struct treap {
	int c[2] = {0,0};
	mt19937::result_type pri = mt();

	hsh hash_val;
	int sz;
	int val;

	void update();

};
const int TREAP_SZ = int(9.1e6);
treap treap_pool[TREAP_SZ];
int TREAP_IND = 1;
int alloc_treap() {
	int n = TREAP_IND++;
	assert(n < TREAP_SZ);
	return n;
}

int get_sz(int a) {
	return a ? treap_pool[a].sz : 0;
}
hsh get_hash_val(int a) {
	return a ? treap_pool[a].hash_val : hsh(0);
}

void treap::update() {
	sz = 1 + get_sz(c[0]) + get_sz(c[1]);
	hash_val = hsh(val);
	if (c[1]) {
		hash_val = hash_val + BASE * get_hash_val(c[1]);
	}
	if (c[0]) {
		hash_val = get_hash_val(c[0]) + BASE_POW[get_sz(c[0])] * hash_val;
	}
}

int merge(int a, int b) {
	if (!a) return b;
	if (!b) return a;
	int n = alloc_treap();
	treap* r = &treap_pool[n];
	if (treap_pool[a].pri < treap_pool[b].pri) {
		*r = treap_pool[a];
		r->c[1] = merge(treap_pool[a].c[1], b);
	} else {
		*r = treap_pool[b];
		r->c[0] = merge(a, treap_pool[b].c[0]);
	}
	r->update();
	return n;
}

pair<int, int> split(int a, int k) {
	if (k == 0) return {0, a};
	assert(a);
	assert(k <= get_sz(a));
	if (k == get_sz(a)) return {a, 0};

	int l, r;

	int n = alloc_treap();
	treap_pool[n] = treap_pool[a];

	if (k <= get_sz(treap_pool[a].c[0])) {
		r = n;
		tie(l, treap_pool[r].c[0]) = split(treap_pool[a].c[0], k);
	} else {
		l = n;
		tie(treap_pool[l].c[1], r) = split(treap_pool[a].c[1], k - 1 - get_sz(treap_pool[a].c[0]));
	}

	treap_pool[n].update();
	assert(get_sz(l) == k);
	return {l, r};
}

const int S = 1 << 17;
struct seg_node {
	int pref = 0;
	int suff = 0;
	bool good = false;
} seg[2*S];

seg_node init_node(int v) {
	int ind = alloc_treap();
	treap* n = &treap_pool[ind];
	n->pri = mt();
	n->c[0] = n->c[1] = 0;
	n->val = abs(v);
	n->update();

	if (v > 0) {
		// this is a suffix
		return {0, ind, true};
	} else {
		// this is a prefix
		return {ind, 0, true};
	}
}

seg_node merge_nodes(seg_node a, seg_node b) {
	if (!a.good || !b.good) {
		return seg_node{0, 0, false};
	}

	int OLD_TREAP_IND = TREAP_IND;

	if (get_sz(a.suff) >= get_sz(b.pref)) {
		auto [x, y] = split(a.suff, get_sz(b.pref));
		assert(get_sz(x) == get_sz(b.pref));
		if (get_hash_val(x) != get_hash_val(b.pref)) {
			TREAP_IND = OLD_TREAP_IND;
			return seg_node{0, 0, false};
		}
		return {a.pref, merge(b.suff, y), true};
	} else {
		auto [x, y] = split(b.pref, get_sz(a.suff));
		assert(get_sz(x) == get_sz(a.suff));
		if (get_hash_val(x) != get_hash_val(a.suff)) {
			TREAP_IND = OLD_TREAP_IND;
			return seg_node{0, 0, false};
		}
		return {merge(a.pref, y), b.suff, true};
	}

	assert(false);
}

void updateNode(int i) {
	if (i >= S) {
		// do nothing
	} else {
		seg[i] = merge_nodes(seg[2*i], seg[2*i+1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	BASE_POW[0] = hsh(1);
	for (int i = 1; i < MAXN; i++) BASE_POW[i] = BASE_POW[i-1] * BASE;

	int N, K; cin >> N >> K;
	vector<int> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];

	auto init = [&]() {
		for (int i = 0; i < N; i++) {
			seg[S+i] = init_node(V[i]);
		}
		for (int i = S-1; i; i--) updateNode(i);
	};
	init();

	const int reset_thresh = int(TREAP_SZ * 0.9);

	int Q; cin >> Q;
	while (Q--) {
		if (TREAP_IND >= reset_thresh) {
			TREAP_IND = 1;
			init();
		}

		int op; cin >> op;
		if (op == 1) {
			int i; cin >> i; i--; cin >> V[i];
			seg[S+i] = init_node(V[i]);
			for (int a = S+i; a; a /= 2) updateNode(a);
		} else if (op == 2) {
			int OLD_TREAP_IND = TREAP_IND;

			int l, r; cin >> l >> r; l--, r--;
			seg_node lval = {0, 0, true};
			seg_node rval = {0, 0, true};
			for (int a = S+l, b = S+r+1; a < b; a /= 2, b /= 2) {
				if (a & 1) lval = merge_nodes(lval, seg[a++]);
				if (b & 1) rval = merge_nodes(seg[--b], rval);
			}

			seg_node val = merge_nodes(lval, rval);
			cout << (val.good && val.pref == 0 && val.suff == 0 ? "Yes" : "No") << '\n';

			TREAP_IND = OLD_TREAP_IND;
		} else assert(false);
	}

	return 0;
}