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

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using num = modnum<int(1e9)+7>;

const int MAXN = 5.1e3;
const int MAXM = 5.1e3;
int N, M;

vector<int> locs[MAXN];
vector<int> Hcnt[MAXN];

int best[MAXN];
num ways[MAXN];

int bestOwn[MAXN];
num waysOwn[MAXN];

int ways2Pref[MAXN];
int ways2Own[MAXN];
int ways1Pref[MAXN];
int ways1Own[MAXN];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int s; scanf("%d", &s); s--;
		locs[s].push_back(i);
	}
	for (int v = 0; v < N; v++) Hcnt[v].resize(locs[v].size());
	for (int m = 0; m < M; m++) {
		int v, h; scanf("%d %d", &v, &h); v--;
		if (h <= int(locs[v].size())) {
			Hcnt[v][h-1]++;
		}
	}

	for (int z = 0; z <= N; z++) best[z] = 0, ways[z] = 1;

	for (int v = 0; v < N; v++) {
		int L = int(locs[v].size());
		for (int i = 0; i <= L+1; i++) {
			ways2Pref[i] = ways2Own[i] = 0;
			ways1Pref[i] = ways1Own[i] = 0;
		}

		for (int i = L-1, cnt = 0; i >= 0; cnt += Hcnt[v][L-1-i], i--) {
			int curCnt = cnt * Hcnt[v][i];
			if (i + i < L-1) curCnt -= Hcnt[v][i]; // same one twice
			ways2Pref[i+1] += curCnt;
			ways2Pref[L-1-i+1] -= curCnt;

			ways2Own[i] = curCnt;

			ways1Pref[i+1] += Hcnt[v][i];
			ways1Pref[L+1] -= Hcnt[v][i];

			ways1Pref[0] += Hcnt[v][i];
			ways1Pref[L-1-i+1] -= Hcnt[v][i];
			
			ways1Own[i] = Hcnt[v][i];
		}
		
		for (int i = 0; i <= L; i++) {
			ways2Pref[i+1] += ways2Pref[i];
			ways1Pref[i+1] += ways1Pref[i];
			int b; num w;
			if (ways2Pref[i]) {
				b = 2;
				w = ways2Pref[i];
			} else if (ways1Pref[i]) {
				b = 1;
				w = ways1Pref[i];
			} else {
				b = 0;
				w = 1;
			}
			int lo = i>0 ? locs[v][i-1]+1 : 0;
			int hi = i<L ? locs[v][i] : N+1;
			best[lo] += b;
			best[hi] -= b;
			ways[lo] *= w;
			ways[hi] /= w;
			
			if (i < L) {
				if (ways2Own[i]) {
					bestOwn[locs[v][i]] = 2, waysOwn[locs[v][i]] = ways2Own[i];
				} else if (ways1Own[i]) {
					bestOwn[locs[v][i]] = 1, waysOwn[locs[v][i]] = ways1Own[i];
				} else {
					bestOwn[locs[v][i]] = 0, waysOwn[locs[v][i]] = 0;
				}
			}
		}
	}

	bestOwn[N] = 0, waysOwn[N] = 1;
	
	int ans = -1; num ansWays = 0;
	for (int i = 0; i <= N; i++) {
		best[i+1] += best[i];
		ways[i+1] *= ways[i];
		best[i] += bestOwn[i];
		ways[i] *= waysOwn[i];
		if (best[i] > ans) ans = best[i], ansWays = ways[i];
		else if (best[i] == ans) ansWays += ways[i];
	}

	printf("%d %d\n", ans, int(ansWays));
	return 0;
}