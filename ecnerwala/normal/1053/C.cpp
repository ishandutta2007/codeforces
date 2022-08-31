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

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
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
using num = modnum<int(1e9)+7>;

using ll = long long;
const int S = (1 << 18);

struct seg_node {
	ll sum_w;
	num sum_aw;
} seg[2 * S];

const int MAXN = 2.1e5;
int N;
int A[MAXN];

void recalc(int i) {
	assert(1 <= i && i < S);
	int l = 2*i, r = 2*i+1;
	seg[i].sum_w = seg[l].sum_w + seg[r].sum_w;
	seg[i].sum_aw = seg[l].sum_aw + seg[r].sum_aw;
}

void update(int i, int nw) {
	assert(0 <= i && i <= N-1);
	seg[S+i].sum_w = nw;
	seg[S+i].sum_aw = num(ll(A[i]) * nw);
	for (int a = (S+i) / 2; a; a /= 2) {
		recalc(a);
	}
}

// sum, half-open
seg_node get_sum(int l, int r) {
	seg_node res{0, 0};
	for (l += S, r += S; l < r; l /= 2, r /= 2) {
		if (l & 1) {
			res.sum_w += seg[l].sum_w;
			res.sum_aw += seg[l].sum_aw;
			l++;
		}
		if (r & 1) {
			r--;
			res.sum_w += seg[r].sum_w;
			res.sum_aw += seg[r].sum_aw;
		}
	}
	return res;
}

num solve(int l, int r) {
	assert(0 <= l && l <= r && r <= N-1);
	r++;
	assert(0 <= l && l < r && r <= N);
	//cerr << "solve" << ' ' << l << ' ' << r << '\n';

	ll pl = get_sum(0, l).sum_w;
	ll pr = get_sum(0, r).sum_w;
	//cerr << pl << ' ' << pr << '\n';
	assert(pl < pr);
	ll pm = (pl + pr) / 2;
	assert(pl <= pm && pm < pr);
	// find the smallest (inclusive) prefix sum > pm
	int m = 1;
	while (m < S) {
		assert(seg[m].sum_w > pm);
		int ml = 2 * m;
		if (seg[ml].sum_w > pm) {
			m = ml;
		} else {
			pm -= seg[ml].sum_w;
			m = ml + 1;
		}
	}
	m -= S;
	//cerr << l << ' ' << m << ' ' << r << '\n';
	assert(l <= m && m < r);
	seg_node sl = get_sum(l, m);
	seg_node sr = get_sum(m, r);
	return (num(A[m]) * num(sl.sum_w) - sl.sum_aw) + (sr.sum_aw - num(A[m]) * num(sr.sum_w));
}

int Q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] -= i;
	}
	for (int i = 0; i < N; i++) {
		int w; cin >> w;
		seg[S+i].sum_w = w;
		seg[S+i].sum_aw = num(ll(A[i]) * w);
	}
	for (int i = S-1; i > 0; i--) {
		recalc(i);
	}

	for (int q = 0; q < Q; q++) {
		int x, y; cin >> x >> y;
		if (x < 0) {
			// do an update
			int i = abs(x); i--;
			int nw = y;
			update(i, nw);
		} else {
			x--, y--;
			cout << solve(x, y) << '\n';
		}
	}

	return 0;
}

// we'll do a_i -= i
// to move box j to box i, you move (a_i - a_j) * w_j