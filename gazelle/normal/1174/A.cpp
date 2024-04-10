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
#define FOR(i,n,m) for(int i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

#include <cstdint>
using i64 = std::int_fast64_t;
const static i64 mod = 1000000007;
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

int main() {
	using mi = mint;
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(2 * n);
	REP(i, 2 * n) cin >> a[i];
	sort(ALL(a));
	ll f = 0, l = 0;
	REP(i, n) f += a[i];
	REP(i, n) l += a[n + i];
	if(f == l) cout << -1 << endl;
	if(f != l) DUMP(a);
	return 0;
}

// ---------------------------------------