#include<bits/stdc++.h>
#define FOR(i, n, m) for(int i = n; i < (int)m; i++)
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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	REP(query, q) {
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n);
		REP(i, n) cin >> a[i];
		sort(ALL(a));
		if(a[0] + 2 * k < a[n - 1]) {
			cout << -1 << endl;
		} else {
			cout << a[0] + k << endl;
		}
	}
	return 0;
}
// ---------------------------------------