#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
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
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 10;
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

using mP = pair<modint, modint>;
//-----------------------------------

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> exi(n, vector<int>(n));
	vector<vector<int>> cost(n, vector<int>(n));
	vector<vector<int>>ids(n, vector<int>(n));
	
	vector<int> vm;
	rep(i, m) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		exi[a][b] = exi[b][a] = true;
		cost[a][b] = cost[b][a] = c - 1;
		ids[a][b] = ids[b][a] = i;
		if (c < 0)vm.push_back(i);
	}
	vector<int> trans(m);
	rep(i, vm.size())trans[vm[i]] = i;
	vector<vector<int>> A;
	rep(i, n)Rep(j, i + 1, n)Rep(k, j + 1, n) {
		if (exi[i][j] && exi[j][k] && exi[i][k]) {
			vector<int> cur(vm.size() + 1);
			vector<P> v = { {i,j},{j,k},{i,k} };
			for (P p : v) {
				int a = p.first, b = p.second;
				if (cost[a][b] >= 0) {
					cur[vm.size()] += cost[a][b];
					if (cur[vm.size()] >= 3)cur[vm.size()] -= 3;
				}
				else {
					int loc = trans[ids[a][b]];
					cur[loc] += 1;
				}
			}
			A.push_back(cur);
		}
	}
	int le = 0;
	rep(j, vm.size()) {
		Rep(i, le, A.size()) {
			if (A[i][j] > 0) {
				swap(A[i], A[le]);
				break;
			}
		}
		if (le<A.size()&&A[le][j] > 0) {
			if (A[le][j] == 2) {
				Rep(k, j, vm.size() + 1) {
					A[le][k] *= 2;
					if (A[le][k] >= 3)A[le][k] -= 3;
				}
			}
			Rep(i, le + 1, A.size()) {
				if (A[i][j] > 0) {
					int coef = A[i][j];
					Rep(k, j, vm.size() + 1) {
						A[i][k] -= A[le][k] * coef;
						while (A[i][k] < 0)A[i][k] += 3;
					}
				}
			}
			le++;
		}
	}
	Rep(i, le, A.size()) {
		if (A[i].back() != 0) {
			cout << -1 << "\n"; return;
		}
	}
	vector<int> res(vm.size()+1);
	res[vm.size()] = 1;
	for (int i = le - 1; i >= 0; i--) {
		int loc = -1;
		rep(j, A[i].size())if (A[i][j] > 0) {
			loc = j; break;
		}
		assert(loc >= 0 && loc < vm.size());
		Rep(j, loc + 1, vm.size() + 1) {
			res[loc] -= res[j] * A[i][j];
		}
		res[loc] %= 3;
		if (res[loc] < 0)res[loc] += 3;
	}
	vector<int> ans(m);
	rep(i, vm.size()) {
		ans[vm[i]] = res[i];
	}
	rep(i, n)Rep(j, i + 1, n)if (exi[i][j])if (cost[i][j] >= 0) {
		ans[ids[i][j]] = cost[i][j];
	}
	rep(i, m)ans[i]++;
	coutarray(ans);
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}