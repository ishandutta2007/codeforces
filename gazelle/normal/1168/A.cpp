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
#define INF 1000000000LL
#define EPS 1e-12
#define FOR(i,n,m) for(lint i=n;i<(int)m;i++)
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

void google_solve() {
	return;
}

void google() {
	int t;
	cin >> t;
	REP(i, t) {
		cout << "Case #" << i + 1 << ": ";
		google_solve();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	int ng = -1, ok = m;
	while(ok - ng > 1) {
		int k = (ng + ok) / 2;
		bool b = true;
		int tmp = 0;
		REP(i, n) {
			if(a[i] + k < m) {
				if(tmp > a[i] + k) b = false;
				else if(tmp < a[i]) {
					tmp = a[i];
				} else {
					tmp = tmp;
				}
			} else {
				int u = (a[i] + k) % m;
				if(tmp <= u) {
					tmp = tmp;
				} else if(tmp < a[i]) {
					tmp = a[i];
				} else {
					tmp = tmp;
				}
			}
		}
		if(b) ok = k;
		else ng = k;
	}
	cout << ok << endl;
	return 0;
}
/* --------------------------------------- */