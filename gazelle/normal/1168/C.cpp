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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	vector<vector<pint>> que(n);
	string ans[300000];
	REP(i, q) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		que[x].pb({y, i});
	}
	int v[20][20];
	REP(i, 20) REP(j, 20) {
		if(i == j) v[i][j] = -1;
		else v[i][j] = INF;
	}
	for(int i = n - 1; i >= 0; i--) {
		bitset<20> bi(a[i]);
		int b = INF;
		REP(j, 20) {
			if(!bi[j]) continue;
			if(b == INF) {
				b = j;
				continue;
			}
			REP(k, 20) {
				v[j][k] = min(v[j][k], max(i, v[b][k]));
			}
			b = j;
		}
		b = INF;
		for(int j = 19; j >= 0; j--) {
			if(!bi[j]) continue;
			if(b == INF) {
				b = j;
				continue;
			}
			REP(k, 20) {
				v[j][k] = min(v[j][k], max(i, v[b][k]));
			}
			b = j;
		}
		REP(j, que[i].size()) {
			bitset<20> bi2(a[que[i][j].first]);
			bool ok = false;
			REP(k, 20) REP(l, 20) {
				if(bi[k] && bi2[l] && v[k][l] <= que[i][j].first) ok = true;
			}
			if(ok) ans[que[i][j].second] = "Shi";
			else ans[que[i][j].second] = "Fou";
		}
	}
	REP(i, q) printf("%s\n", ans[i].c_str());
	return 0;
}
/* --------------------------------------- */