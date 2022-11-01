#include<bits/stdc++.h>
#define FOR(i, n, m) for(long long i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = std::int_fast64_t;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 1000000007;
constexpr long double eps = 1e-15;
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
	os << to_string(p.first) << " " << to_string(p.second);
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	REP(i, v.size()) {
		if(i) os << " ";
		os << to_string(v[i]);
	}
	return os;
}

/*
template<typename T>
struct Treap {
	double drand() { // random number in [0, 1]
		static random_device rd;
		static mt19937 mt(rd());
		return (unsigned)mt() / (double)numeric_limits<unsigned>::max();
	}
	T v;
	double p;
	int cnt;
	Treap* lch;
	Treap* rch;
	Treap(T v) : v(v), p(drand()), cnt(1), lch(NULL), rch(NULL) { }
	Treap* update() {
		this->size = size(this->lch) + size(this->rch) + 1;
		return this;
	}
	static int size(Treap* t) {
		if(!t) return 0;
		else return t->cnt;
	}
	static Treap* merge(Treap* l, Treap* r) {
		if(!l || !r) {
			if(!l) return r;
			else return l;
		}
		if(l->p >= r->p) {
			l->rch = merge(l->rch, r);
			return l->update();
		} else {
			r->lch = merge(r->lch, l);
			return r->update();
		}
	}
	static pair<Treap*, Treap*> split(Treap* t, int k) {
		// split [0, k) and [k, n)
		if(k == 0) return {NULL, t};
		if(!(t->l)) {
			auto tmp = split(t->r, k - 1);
			t->r = tmp.first;
			return {t->update(), tmp.second};
		} else if(!(t->r)) {
			auto tmp = split(t->r, k - 1);
			t->r = tmp.first;
			return {t->update(), tmp.second};
		} else {

		}
	}
	Treap* insert() {
	}
	Treap* erase() {
	}
	T operator[](int k) {
	}
};
*/

template <typename T> struct segment_tree {
private:
	int n;
	const function<T(T, T)> op;
	const T ie;
	vector<T> seq;

public:
	segment_tree(int _n, function<T(T, T)> op, const T ie) : op(op), ie(ie) {
		n = 1;
		while(n < _n) n *= 2;
		seq.resize(2 * n - 1);
		for(int i = 0; i < 2 * n - 1; i++) seq[i] = ie;
	}

	void update(int k, const T e) {
		k += n - 1;
		seq[k] = e;
		while(k > 0) {
			k = (k - 1) / 2;
			seq[k] = op(seq[k * 2 + 1], seq[k * 2 + 2]);
		}
	}

	T get(int k) {
		k += n - 1;
		return seq[k];
	}

	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if(r == -1) r = n;
		if(r <= a || b <= l) return ie;
		if(a <= l && r <= b) return seq[k];
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return op(vl, vr);
	}
};
// segment_tree<ll> rsq(n, [] (ll a, ll b) { return a + b; }, 0)
// segment_tree<ll> rMq(n, [] (ll a, ll b) { return max(a, b); }, -1e18)
// segment_tree<ll> rmq(n, [] (ll a, ll b) { return min(a, b); }, 1e18)

vector<vector<int>> g;
vector<ll> dp;
vector<int> tsize;
int n;

int calc(int v, int p) {
	int sum = 1;
	for(auto nv: g[v]) {
		if(nv == p) continue;
		sum += calc(nv, v);
	}
	return tsize[v] = sum;
}

ll dfs1(int v, int p) {
	ll ret = tsize[v];
	for(auto nv: g[v]) {
		if(nv == p) continue;
		ret += dfs1(nv, v);
	}
	return dp[v] = ret;
}

ll dfs2(int v, int p, ll cost) {
	ll ret = cost;
	for(auto nv: g[v]) {
		if(nv == p) continue;
		ret += dp[nv];
	}
	ll sum = ret;
	for(auto nv: g[v]) {
		if(nv == p) continue;
		ret = max(ret, dfs2(nv, v, sum - dp[nv] + (n - tsize[nv])));
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	g.resize(n);
	dp.assign(n, -1);
	tsize.resize(n);
	REP(i, n - 1) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	calc(0, -1);
	dfs1(0, -1);
	cout << dfs2(0, -1, 0) + n << endl;
	return 0;
}
// ---------------------------------------