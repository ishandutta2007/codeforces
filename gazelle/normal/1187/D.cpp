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


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	REP(testcase, t) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		REP(i, n) cin >> a[i];
		REP(i, n) cin >> b[i];
		REP(i, n) a[i]--;
		REP(i, n) b[i]--;
		segment_tree<ll> rmq(n, [] (int a, int b) { return min(a, b); }, inf);
		REP(i, n) rmq.update(i, a[i]);
		vector<vector<int>> c(n);
		vector<int> ite(n, 0);
		REP(i, n) c[a[i]].pb(i);
		bool ok = true;
		REP(i, n) {
			if(ite[b[i]] == (int)c[b[i]].size()) {
				ok = false;
				break;
			}
			int idx = c[b[i]][ite[b[i]]];
			ite[b[i]]++;
			if(rmq.query(0, idx) < b[i]) {
				ok = false;
				break;
			}
			rmq.update(idx, inf);
		}
		if(ok)  cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}
// ---------------------------------------