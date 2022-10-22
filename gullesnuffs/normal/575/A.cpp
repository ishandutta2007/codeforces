#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

static ll mod;

template <class T> struct Matrix {
	typedef Matrix M;
	typedef const M& R;
	static const int r = 2, c = 2;
	array<T, 4> d;
	Matrix() { rep(i,0,4) d[i] = 0; }
	Matrix(int _r, int _c) { rep(i,0,4) d[i] = 0; }
	T& operator()(int row, int col) { return d[row*c + col]; }
	const T& operator()(int row, int col) const { return d[row*c + col]; }
#define OP(op, o) M operator op(R m) const { \
	M a(r,c); rep(i,0,r*c) a.d[i] = d[i] o m.d[i] % mod; return a; } \
	M operator o(T v) const { \
	M a(r,c); rep(i,0,r*c) a.d[i] = d[i] o v % mod; return a; }
	OP(+,+)
	OP(-,-)
	OP(->*,*)
	OP(/,/)
	bool operator==(const M& m) const {
		if (r != m.r || c != m.c) return false;
		rep(i,0,r*c) if (d[i] != m.d[i]) return false;
		return true;
	}
	M operator*(R m) const {
		assert(c == m.r);
		M a(r, m.c);
		rep(i,0,r) rep(j,0,m.c) {
			rep(k,0,c) a(i,j) += operator()(i,k)*m(k,j);
			a(i,j) %= mod;
		}
		return a;
	}
	array<T, 2> operator*(const array<T, 2>& vec) const {
		array<T, 2> ret = {
			((*this)(0,0) * vec[0] + (*this)(0,1) * vec[1]) % mod,
			((*this)(1,0) * vec[0] + (*this)(1,1) * vec[1]) % mod
		};
		return ret;
	}
	M operator^(ll p) const {
		M a(r, c), b(*this);
		rep(i,0,r) a(i,i) = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};

typedef Matrix<ll> M;

struct Tree {
	typedef M T;
	static T LOW;
	T f(T a, T b) { return b * a; }

	int n;
	vector<T> s;
	Tree() {}
	Tree(int m, T def=LOW) { init(m, def); }
	void init(int m, T def) {
		n = 1; while (n < m) n *= 2;
		s.assign(n + m, def);
		s.resize(2 * n, LOW);
		for (int i = n; i --> 1; )
			s[i] = f(s[i * 2], s[i*2 + 1]);
	}
	void update(int pos, T val) {
		pos += n;
		s[pos] = val;
		for (pos /= 2; pos >= 1; pos /= 2)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int a, int b) { return que(1, a, b, 0, n); }
	T que(int pos, int a, int b, int x, int y) {
		if (a >= b) return LOW;
		if (a == x && b == y) return s[pos];
		int m = (x + y) / 2;
		return f(que(2 * pos, a, min(b, m), x, m),
				que(2 * pos + 1, max(a, m), b, m, y));
	}
};
M Tree::LOW{2,2};

int main() {
	cin.sync_with_stdio(false);
	Tree::LOW = M(2,2);
	Tree::LOW(0,0) = 1;
	Tree::LOW(1,0) = 0;
	Tree::LOW(0,1) = 0;
	Tree::LOW(1,1) = 1;
	ll K;
	cin >> K >> mod;
	int N;
	cin >> N;
	vector<ll> sbase(N);
	rep(i,0,N) {
		cin >> sbase[i] , sbase[i] %= mod;
	}
	deque<pair<ll, M> > edits;
	auto getm = [&](ll pos) -> M& {
		if (!edits.empty() && edits.back().first == pos)
			return edits.back().second;
		M m(2, 2);
		m(0,0) = sbase[(pos+1) % N];
		m(0,1) = sbase[pos % N];
		m(1,0) = 1;
		m(1,1) = 0;
		edits.emplace_back(pos, m);
		return edits.back().second;
	};
	{
		int M_;
		cin >> M_;
		vector<pair<ll, ll> > v;
		rep(i,0,M_) {
			ll j, w;
			cin >> j >> w;
			v.emplace_back(j, w % mod);
		}
		sort(all(v));
		rep(i,0,M_) {
			M& m = getm(v[i].first-1);
			m(0,0) = v[i].second;
			M& m2 = getm(v[i].first);
			m2(0,1) = v[i].second;
		}
	}

	M wholem(2,2);
	vector<M> mbase(N);
	rep(i,0,2) wholem(i,i) = 1, wholem(i,1-i) = 0;
	Tree tr(N);
	rep(i,0,N) {
		M m(2, 2);
		m(0,0) = sbase[(i+1) % N];
		m(0,1) = sbase[i % N];
		m(1,0) = 1;
		m(1,1) = 0;
		mbase[i] = m;
		wholem = m * wholem;
		tr.update(i, m);
	}
	// assert(tr.query(0,N) == wholem);

	array<ll, 2> vec = {1, 0};
	ll at = 0;
	while (at + N <= K) {
		ll to = K;
		if (!edits.empty()) to = min(to, edits.front().first);
		ll wholeSteps = (to - at) / N;
		if (wholeSteps) {
			vec = (wholem ^ wholeSteps) * vec;
			at += N * wholeSteps;
		}
		else {
			ll curdiv = at / N;

			vi sets;
			while (!edits.empty() && edits.front().first / N == curdiv) {
				int p = (int)(edits.front().first % N);
				tr.update(p, edits.front().second);
				edits.pop_front();
				sets.push_back(p);
			}

			vec = tr.query(0,N) * vec;
			trav(p, sets) tr.update(p, mbase[p]);

			at += N;
		}
	}

	map<ll, M> editsm;
	trav(pa, edits) editsm[pa.first] = pa.second;
	while (at < K) {
		M m = mbase[(int)(at % N)];
		if (editsm.count(at)) m = editsm[at];
		vec = m * vec;
		++at;
	}

	ll res = vec[1];
	res %= mod;
	if (res < 0) res += mod;
	cout << res << endl;
}