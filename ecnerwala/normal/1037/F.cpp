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
using num = modnum<int(1e9) + 7>;

const int MAXN = 1.1e6;
int N;
int A[MAXN];

const int MAXK = MAXN;
int K;
num prefDiff[MAXK];
int curInd;
num curBest;

void applyRange(int a, int b, num v) {
	//cerr << "Adding mod K " << a << ' ' << b << ' ' << v << '\n';
	assert(a <= b);
	assert(0 <= a && b <= K);
	assert(0 < curInd && curInd <= K);
	if (a < curInd && curInd <= b) {
		curBest += v;
	}
	prefDiff[a%K] += v;
	prefDiff[b%K] -= v;
}

void increment() {
	assert(0 < curInd && curInd <= K);
	curBest += prefDiff[curInd % K];
	curInd %= K;
	curInd++;
}

// v is the maximum value
// a and b are the range in 0..N
// a is exclusive, b is inclusive
void addRange(int a, int b, num v) {
	//cerr << "Adding " << a << ' ' << b << ' ' << v << '\n';
	assert(a < b);
	if (b / K > a / K) {
		// we loop, so just add twice
		applyRange(0, b % K, v);
		applyRange(a % K, K, v);

		if (b / K - a / K > 1) {
			applyRange(0, K, v * num(b / K - a / K - 1));
		}
	} else {
		assert(a % K <= b % K);
		applyRange(a % K, b % K, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> K; K--;
	A[0] = int(2e9);
	for (int i = 1; i <= N; i++) cin >> A[i];

	stack<pair<int, int>> bests;
	bests.emplace(0, A[0]);

	curInd = 1;

	num res = 0;
	for (int i = 1; i <= N; i++) {
		while (bests.top().second <= A[i]) {
			pair<int, int> cur = bests.top();
			bests.pop();
			assert(!bests.empty());
			addRange(bests.top().first, cur.first, -num(cur.second));
		}
		pair<int, int> cur(i, A[i]);
		addRange(bests.top().first, cur.first, num(cur.second));
		bests.push(cur);
		//cerr << curInd << ' ' << curBest << '\n';
		res += curBest - A[i]; // have to subtract out yourself
		//cerr << curInd << ' ' << curBest << '\n';
		increment();
	}
	cout << res << '\n';

	return 0;
}