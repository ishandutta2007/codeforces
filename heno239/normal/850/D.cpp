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
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
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
const ld pi = acos(-1.0);

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

const int max_n = 1 << 20;
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

struct ste {
	int i, j, k;
};
ste pre[32][70][70 * 31];
bool exi[32][70][70 * 31];
void solve() {
	int m; cin >> m;
	vector<int> a(m); rep(i, m)cin >> a[i];
	sort(all(a));
	exi[0][0][0] = true;
	pre[0][0][0].i = -1;
	rep(i, m) {
		rep(j, 69) {
			rep(k, 30 * j + 1) {
				if (exi[i][j][k]) {
					if (pre[i][j][k].i==i) {
						exi[i + 1][j][k] = true;
						pre[i + 1][j][k] = { i,j,k };
					}
					if (k + a[i] >= (j + 1) * j / 2) {
						exi[i][j + 1][k + a[i]] = true;
						pre[i][j + 1][k + a[i]] = { i,j,k };
					}
				}
			}
		}
	}
	int chk = -1;
	for (int n = 1; n <= 69; n++) {
		if (exi[m][n][n * (n - 1) / 2]) {
			chk = n; break;
		}
	}
	int n = chk;
	if (n < 0) {
		cout << "=(\n"; return;
	}
	vector<int> ds;
	int ci = m, cj = n, ck = n * (n - 1) / 2;
	while (ci > 0 || cj > 0 || ck > 0) {
		ste s = pre[ci][cj][ck];
		if (s.j != cj) {
			ds.push_back(ck - s.k);
		}
		ci = s.i, cj = s.j, ck = s.k;
	}
	vector<string> ans(n);
	rep(i, n)ans[i].resize(n, '0');
	vector<bool> used(n);
	//rep(i, n)cout << ds[i] << "\n";
	rep(i, n) {
		vector<P> v;
		rep(j, n)if (!used[j]) {
			v.push_back({ ds[j],j });
		}
		sort(all(v));
		int id = v.back().second;
		int num = v.back().first;
		rep(j, (int)v.size() - 1) {
			int to = v[j].second;
			if (j < num) {
				ans[id][to] = '1';
			}
			else {
				ans[to][id] = '1';
				ds[to]--;
			}
		}
		used[id] = true;
	}
	cout << n << "\n";
	rep(i, n)cout << ans[i] << "\n";
}





signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;

}