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
constexpr ll mod = 998244353;
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

const int max_n = 1 << 18;
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
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
		ret[i][j] += lhs[i][k] * rhs[k][j];
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

pair<mat, vector<int>> LUPDecomposition(mat a) {
	int n = a.size();
	vector<int> perm(n);
	iota(begin(perm), end(perm), 0);
	rep(i, n) {
		int pivot = i;
		for (int j = i + 1; j < n; ++j)
			if (abs(a[j][i]) > abs(a[pivot][i]))pivot = j;
		swap(a[pivot], a[i]);
		swap(perm[pivot], perm[i]);
		for (int j = i + 1; j < n; ++j) {
			a[j][i] = a[j][i]/a[i][i];
			for (int k = i + 1; k < n; ++k) {
				a[j][k] += (modint)-a[i][k] * a[j][i];
			}
		}
	}
	return make_pair(a, perm);
}
Array LUPBackSubstitution(mat& LU, vector<int>& perm, Array a) {
	int n = LU.size();
	Array tmp(n);
	rep(i, n)tmp[i] = a[perm[i]];
	swap(tmp, a);
	rep(i, n) {
		rep(j, i) {
			a[i] = (modint)-a[j] * LU[i][j] + a[i];
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			a[i] = (modint)-a[j] * LU[i][j] + a[i];
		}
		a[i] = a[i]/LU[i][i];
	}
	return a;
}

//Ax=bx
Array calc(mat A, Array b) {
	pair<mat, vector<int>> p = LUPDecomposition(A);
	return LUPBackSubstitution(p.first, p.second, b);
}

int memo[1 << 18];
int mex(vector<int> v) {
	rep(i, v.size()+1)memo[i] = 0;
	for (int id : v) {
		memo[id] = 1;
	}
	rep(i, v.size()+1)if (!memo[i])return i;
	return v.size();
}
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> G(n),rG(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		rG[b].push_back(a);
	}
	vector<int> grundy(n);
	
	vector<int> cnt(n); queue<int> q;
	rep(i, n) {
		cnt[i] = G[i].size();
		if (cnt[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int v = q.front(); q.pop();
		vector<int> vg;
		for (int to : G[v])vg.push_back(grundy[to]);
		grundy[v] = mex(vg);
		for (int to : rG[v]) {
			cnt[to]--;
			if (cnt[to] == 0) {
				q.push(to);
			}
		}
	}
	//cout << "hello\n";
	int ma = 0; rep(i, n)ma = max(ma, grundy[i]);
	cnt.clear();
	cnt.resize(ma + 1,0);
	vector<modint> prob(ma + 1);
	rep(i, n)cnt[grundy[i]]++;
	rep(j, ma + 1)prob[j] = (modint)cnt[j] / (modint)(n + 1);
	int sup = 1; while (sup <= ma)sup *= 2;
	mat mt(sup, Array(sup));
	rep(i, sup) {
		mt[i][i] += 1;
		rep(j, ma + 1) {
			int to = i ^ j;
			mt[i][to] -= prob[j];
		}
	}
	//rep(i, sup)rep(j, sup)cout << mt[i][j] << "\n";
	Array las(sup); las[0] = (modint)1 / (modint)(n + 1);
	Array pp = calc(mt, las);
	modint ans = pp[0]; ans = (modint)1 - ans;
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