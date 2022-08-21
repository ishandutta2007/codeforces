#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 17;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}

typedef modint Data;
typedef vector<Data> Array;
typedef vector<Array> mat;

bool is_zero(Data dat) { return abs(dat) < eps; }
mat operator-(mat a) {
	rep(i, a.size())rep(j, a[0].size())a[i][j] = -a[i][j];
	return a;
}
mat operator+(mat lhs, mat& rhs) {
	rep(i, lhs.size())rep(j, lhs[0].size())lhs[i][j] += rhs[i][j];
	return lhs;
}
mat operator-(mat lhs, mat& rhs) {
	rep(i, lhs.size())rep(j, lhs[0].size())lhs[i][j] -= rhs[i][j];
	return lhs;
}
mat operator*(const mat& lhs, const mat& rhs) {
	mat ret(lhs.size(), Array(rhs[0].size(), 0));
	rep(i, lhs.size())rep(j, rhs[0].size())rep(k, rhs.size()) {
		ret[i][j] = lhs[i][k] * rhs[k][j] + ret[i][j];
	}
	return ret;
}

mat scalar(int sz, Data k) {
	mat ret(sz, Array(sz, 0));
	rep(i, sz)ret[i][i] = k;
	return ret;
}
//
mat operator^(const mat& lhs, const ll n) {
	if (n == 0)return scalar(lhs.size(), 1);
	mat ret = (lhs * lhs) ^ (n / 2);
	if (n % 2) {
		ret = ret * lhs;
	}
	return ret;
}

Data det(mat a) {
	const int n = a.size();
	Data D = Data(1);
	for (int i = 0; i < n; ++i) {
		int pivot = i;
		for (int j = i + 1; j < n; ++j) {
			if (abs(a[j][i]) > abs(a[pivot][i]))pivot = j;
		}
		swap(a[pivot], a[i]);
		D = D * a[i][i] * Data(i != pivot ? -1 : 1);
		if (is_zero(a[i][i]))break;
		for (int j = i + 1; j < n; ++j) {
			for (int k = n - 1; k >= i; --k) {
				a[j][k] = a[j][k] - a[i][k] * a[j][i] / a[i][i];
			}
		}
	}
	return D;
}

struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};
void solve() {
	int n, m; cin >> n >> m >> mod;
	vector<string> s(n);
	rep(i, n)cin >> s[i];
	uf u((n + 1) * (m + 1));
	uf z((n + 1) * (m + 1));
	rep(i, n)rep(j, m) {
		if (s[i][j] == '/') {
			u.unite(i * (m + 1) + j + 1, (i + 1) * (m + 1) + j);
			z.unite(i * (m + 1) + j + 1, (i + 1) * (m + 1) + j);
		}
		else if(s[i][j]=='\\'){
			u.unite(i * (m+1) + j, (i + 1) * (m + 1) + j + 1);
			z.unite(i * (m+1) + j, (i + 1) * (m + 1) + j + 1);
		}
		else {
			z.unite(i * (m + 1) + j + 1, (i + 1) * (m + 1) + j);
			z.unite(i * (m+1) + j, (i + 1) * (m + 1) + j + 1);
		}
	}
	modint ans = 0;
	rep(k, 2) {
		vector<int> ids;
		rep(i, n + 1)rep(j, m + 1) {
			if ((i + j) % 2 == k) {
				ids.push_back(z.find(i * (m + 1) + j));
			}
		}
		sort(all(ids));
		ids.erase(unique(all(ids)), ids.end());
		if (ids.size() != 1)continue;

		ids.clear();
		rep(i, n + 1)rep(j, m + 1) {
			if ((i + j) % 2 == k) {
				ids.push_back(u.find(i * (m + 1) + j));
			}
		}
		sort(all(ids));
		ids.erase(unique(all(ids)), ids.end());
		mat mt(ids.size(), vector<modint>(ids.size()));
		rep(i, n)rep(j, m) {
			if (s[i][j] == '*') {
				int fr, to;
				if ((i + j) % 2 == k) {
					fr = i * (m + 1) + j;
					to = (i + 1) * (m + 1) + j + 1;
				}
				else {
					fr = i * (m + 1) + j+1;
					to = (i + 1) * (m + 1) + j;
				}
				fr = u.find(fr);
				to = u.find(to);
				fr = lower_bound(all(ids), fr) - ids.begin();
				to = lower_bound(all(ids), to) - ids.begin();
				mt[fr][fr] += 1;
				mt[to][to] += 1;
				mt[fr][to] -= 1;
				mt[to][fr] -= 1;
			}
		}
		/*cout << k << "\n";
		rep(i, ids.size()){
			rep(j, ids.size()) {
				cout << mt[i][j] << " ";
			}
			cout << "\n";
		}*/
		mt.pop_back();
		rep(i, mt.size())mt[i].pop_back();
		ans += det(mt);
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}