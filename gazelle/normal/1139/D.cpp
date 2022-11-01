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
using lint = long long;
using ld = long double;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(lint i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

#include <cstdint>
struct mint {
	using i64 = std::int_fast64_t;
	const static i64 mod = 1000000007;
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> m;
	if(m == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<mint> dp(m + 1);
	for(int i = m; i > 1; i--) {
		mint tmp = mint(m) / mint(m - m / i);
		tmp -= mint(m - m / i) / mint(m);
		for(int j = 2; i * j <= m; j++) tmp -= dp[i * j];
		dp[i] = tmp;
	}
	mint ans = 0;
	FOR(i, 2, m + 1) ans += dp[i];
	ans += 1 / mint(m);
	cout << ans << endl;
	return 0;
}
/* --------------------------------------- */