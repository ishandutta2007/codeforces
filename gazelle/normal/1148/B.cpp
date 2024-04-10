#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
#include<cassert>
#include<random>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
#define INF 1000000000LL
#define EPS 1e-12
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

#include <cstdint>
using i64 = std::int_fast64_t;
const static i64 mod = 1000003;
struct mint {
	i64 n;
public:
	mint(const i64 n = 0) : n((n % mod + mod) % mod) {}
	mint pow(int m) const {
		i64 a = n, r = 1;
		while(m > 0) {
			if(m & 1) { r *= a; r %= mod; }
			a = (a * a) % mod; m /= 2;
		}
		return mint(r);
	}
	mint &operator++() { *this += 1; return *this; }
	mint &operator--() { *this -= 1; return *this; }
	mint operator++(int) { mint ret = *this; *this += 1; return ret; }
	mint operator--(int) { mint ret = *this; *this -= 1; return ret; }
	mint operator~() const { return (this -> pow(mod - 2)); } // inverse
	friend bool operator==(const mint& lhs, const mint& rhs) {
		return lhs.n == rhs.n;
	}
	friend bool operator<(const mint& lhs, const mint& rhs) {
		return lhs.n < rhs.n;
	}
	friend bool operator>(const mint& lhs, const mint& rhs) {
		return lhs.n > rhs.n;
	}
	friend mint &operator+=(mint& lhs, const mint& rhs) {
		lhs.n += rhs.n;
		if (lhs.n >= mod) lhs.n -= mod;
		return lhs;
	}
	friend mint &operator-=(mint& lhs, const mint& rhs) {
		lhs.n -= rhs.n;
		if (lhs.n < 0) lhs.n += mod;
		return lhs;
	}
	friend mint &operator*=(mint& lhs, const mint& rhs) {
		lhs.n = (lhs.n * rhs.n) % mod;
		return lhs;
	}
	friend mint &operator/=(mint& lhs, const mint& rhs) {
		lhs.n = (lhs.n * (~rhs).n) % mod;
		return lhs;
	}
	friend mint operator+(const mint& lhs, const mint& rhs) {
		return mint(lhs.n + rhs.n);
	}
	friend mint operator-(const mint& lhs, const mint& rhs) {
		return mint(lhs.n - rhs.n);
	}
	friend mint operator*(const mint& lhs, const mint& rhs) {
		return mint(lhs.n * rhs.n);
	}
	friend mint operator/(const mint& lhs, const mint& rhs) {
		return mint(lhs.n * (~rhs).n);
	}
};
istream& operator>>(istream& is, mint& m) { is >> m.n; return is; }
ostream& operator<<(ostream& os, mint& m) { os << m.n; return os; }

template <typename T>
class SegTree {
private:
	int n;
	const function<T(T, T)> op; // 
	const T ie; // 
	vector<T> seq;

public:
	/// op: , ie: 
	SegTree(int _n, function<T(T, T)> op, const T ie) : op(op), ie(ie) {
		n = 1;
		while(n < _n) n *= 2;
		seq.resize(2 * n - 1);
		for(int i = 0; i < 2 * n - 1; i++) seq[i] = ie;
	}

	/// k (0-indexed) e 
	void update(int k, const T e) {
		k += n - 1;
		seq[k] = e;
		while(k > 0) {
			k = (k - 1) / 2;
			seq[k] = op(seq[k * 2 + 1], seq[k * 2 + 2]);
		}
	}

	// k (0-indexed)
	T get(int k) {
		k += n - 1;
		return seq[k];
	}

	/// [a, b) (0-indexed)
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if(r == -1) r = n;
		if(r <= a || b <= l) return ie;
		if(a <= l && r <= b) return seq[k];
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return op(vl, vr);
	}
};
// [Range Sum Query] rsq(n, [] (ll a, ll b) { return a + b; }, 0)
// [Range Max Query] rMq(n, [] (ll a, ll b) { return max(a, b); }, -1e18)
// [Range Min Query] rmq(n, [] (ll a, ll b) { return min(a, b); }, 1e18)

class union_find {
public:
	union_find(int n)
	: par_(n, -1)
	{}
	void init(int n) {
		par_.assign(n, -1);
	}

	int root(int x) {
		return par_[x] < 0 ? x : par_[x] = root(par_[x]);
	}

	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if(x == y) {
			return false;
		} else {
			if(par_[x] < par_[y]) {
				par_[x] += par_[y];
				par_[y] = x;
			} else {
				par_[y] += par_[x];
				par_[x] = y;
			}
			return true;
		}
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	int size(int x) {
		return -par_[root(x)];
	}

private:
	std::vector<int> par_;
};

mint _pow(mint a, long long n) {
	if(n == 0) return 1;
	mint res = 1;
	mint buf = a;
	while(n > 0) {
		if(n % 2) res *= buf;
		buf *= buf;
		n /= 2;
	}
	return res;
}

#define MAX_N 1000000
long long extgcd(long long a, long long b, long long& x, long long& y) {
	long long d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}
long long mod_inverse(long long a, long long m) {
	long long x, y;
	if(extgcd(a, m, x, y) == 1) return (m + x % m) % m;
	else return -1;
}
vector<long long> fact(MAX_N+1, INF);
long long mod_fact(long long n, long long& e) {
	if(fact[0] == INF) {
		fact[0]=1;
		if(MAX_N != 0) fact[1]=1;
		for(ll i = 2; i <= MAX_N; ++i) {
			fact[i] = (fact[i-1] * i) % mod;
		}
	}
	e = 0;
	if(n == 0) return 1;
	long long res = mod_fact(n / mod, e);
	e += n / mod;
	if((n / mod) % 2 != 0) return (res * (mod - fact[n % mod])) % mod;
	return (res * fact[n % mod]) % mod;
}
// return nCk
long long mod_comb(long long n, long long k) {
	if(n < 0 || k < 0 || n < k) return 0;
	long long e1, e2, e3;
	long long a1 = mod_fact(n, e1), a2 = mod_fact(k, e2), a3 = mod_fact(n - k, e3);
	if(e1 > e2 + e3) return 0;
	return (a1 * mod_inverse((a2 * a3) % mod, mod)) % mod;
}

using mi = mint;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	vector<ll> a(n), b(m);
	REP(i, n) cin >> a[i];
	REP(i, m) cin >> b[i];
	if(k >= min(n, m)) {
		cout << -1 << endl;
		return 0;
	}
	ll ans = 0;
	b.pb(INF * INF);
	REP(i, k + 1) {
		auto ite = lower_bound(ALL(b), a[i] + ta);
		if((ite - b.begin()) + (k - i) >= m) {
			cout << -1 << endl;
			return 0;
		} else ans = max(ans, b[ite - b.begin() + (k - i)] + tb);
	}
	cout << ans << endl;
	return 0;
}

// ---------------------------------------