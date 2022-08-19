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
using num = modnum<998244353>;
using ll = long long;

struct mat {
	num v[2][2];
	mat() {}
	explicit mat(num x) {
		v[0][0] = v[1][1] = x;
		v[0][1] = v[1][0] = 0;
	}
	friend mat operator * (const mat& A, const mat& B) {
		mat R;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					R.v[i][j] += A.v[i][k] * B.v[k][j];
				}
			}
		}
		return R;
	}
};

const int S = 1 << 18;
mat seg[2*S];

void propogate(int n) {
	if (n >= S) return;
	seg[2*n+0] = seg[2*n+0] * seg[n];
	seg[2*n+1] = seg[2*n+1] * seg[n];
	seg[n] = mat(1);
}
void propogate_all(int n) {
	if (!n) return;
	propogate_all(n/2);
	propogate(n);
}

// half-open range
void update(int l, int r, mat v) {
	assert(l <= r);
	if (l == r) return;
	propogate_all(S+l);
	propogate_all(S+r-1);
	for (int a = S+l, b = S+r; a < b; a /= 2, b /= 2) {
		if (a & 1) {
			seg[a] = seg[a] * v;
			a++;
		}
		if (b & 1) {
			--b;
			seg[b] = seg[b] * v;
		}
	}
}

const int MAXN = 1.1e5;
int N;
ll X[MAXN];
ll V[MAXN];
num P[MAXN];

struct frac {
	ll p, q;
	friend std::ostream& operator << (std::ostream& o, const frac& f) { return o << f.p << '/' << f.q; }
	friend bool operator < (const frac& a, const frac& b) {
		assert(a.p || a.q);
		return a.p * b.q < b.p * a.q;
	}
	friend bool operator == (const frac& a, const frac& b) {
		return a.p * b.q == b.p * a.q;
	}

	explicit operator num() const {
		return num(p) / num(q);
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	num inv100 = inv(num(100));
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> V[i] >> P[i];
		P[i] *= inv100;
	}

	vector<frac> evts;
	evts.push_back(frac{0,1});
	evts.push_back(frac{1,0});
	for (int i = 0; i+1 < N; i++) {
		assert(X[i+1] > X[i]);
		frac fMeet{X[i+1] - X[i], V[i] + V[i+1]};
		evts.push_back(fMeet);

		frac fAway{X[i+1] - X[i], abs(V[i] - V[i+1])};
		evts.push_back(fAway);
	}
	sort(evts.begin(), evts.end());
	evts.resize(unique(evts.begin(), evts.end()) - evts.begin());

	int M = int(evts.size());

	bool endInf = evts.back() == frac{1,0};
	assert(endInf);

	for (int i = 1; i < 2*S; i++) {
		seg[i] = mat(1);
	}

	seg[1] = mat();
	seg[1].v[0][0] = 1-P[0];
	seg[1].v[0][1] = P[0];

	for (int i = 0; i+1 < N; i++) {
		frac fMeet{X[i+1] - X[i], V[i] + V[i+1]};
		int iMeet = int(lower_bound(evts.begin(), evts.end(), fMeet) - evts.begin());

		frac fAway{X[i+1] - X[i], abs(V[i] - V[i+1])};
		int iAway = int(lower_bound(evts.begin(), evts.end(), fAway) - evts.begin());

		vector<int> inds;
		inds.push_back(0);
		inds.push_back(iMeet);
		inds.push_back(iAway);
		inds.push_back(M);
		sort(inds.begin(), inds.end());
		for (int z = 0; z+1 < int(inds.size()); z++) {
			int l = inds[z], r = inds[z+1];
			mat v;
			v.v[0][1] = P[i+1];
			if (l < iMeet) {
				v.v[1][0] = 1-P[i+1];
			}
			if (V[i] >= V[i+1] || l < iAway) {
				v.v[0][0] = 1-P[i+1];
			}
			if (V[i+1] >= V[i] || l < iAway) {
				v.v[1][1] = P[i+1];
			}

			update(l, r, v);
		}
	}

	for (int i = 1; i < S; i++) {
		propogate(i);
	}

	num ans = 0;
	num pInf = (seg[S+M-1].v[0][0] + seg[S+M-1].v[0][1]);
	for (int i = 0; i+1 < M-1; i++) {
		num prob = (seg[S+i].v[0][0] + seg[S+i].v[0][1]);
		prob -= pInf;
		num t = num(evts[i+1]) - num(evts[i]);
		//cerr << evts[i] << '-' << evts[i+1] << ' ' << prob << '\n';
		ans += t * prob;
	}
	cout << ans << '\n';

	return 0;
}