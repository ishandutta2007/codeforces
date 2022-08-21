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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
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
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 1;
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

LP input_point() {
	int x, y; cin >> x >> y;
	return { x,y };
}
ll dot(LP a, LP b) {
	return a.first * b.first + a.second * b.second;
}
ll cross(LP a, LP b) {
	return a.first * b.second - a.second * b.first;
}
ll norm2(LP a) {
	return a.first * a.first + a.second * a.second;
}
int ccw(LP a, LP b, LP c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	if (cross(b, c) > 0)return 1;//counter clockwise
	if (cross(b, c) < 0)return -1;//clockwise
	if (dot(b, c) < 0)return 2;//c--a--b on line
	if (norm2(b) < norm2(c))return -2;//a--b--c on line
	return 0;//a--c--b on line
}

vector<int> pres[7][1000];
void solve() {
	int k, n; cin >> k >> n;
	vector<LP> a(k);
	rep(i, k) {
		a[i] = input_point();
	}
	vector<LP> b(n);
	rep(i, n) {
		b[i] = input_point();
	}
	rep(i, k) {
		rep(j, n) {
			rep(x, n)if (j != x) {
				if (ccw(a[i], b[x], b[j]) == -2) {
					pres[i][j].push_back(x);
				}
			}
			if (pres[i][j].size() > k)pres[i][j].resize(k);
		}
	}

	vector<vector<vector<vector<int>>>> cs(1 << k);
	rep(i, (1 << k)) {
		int cnt = 0;
		rep(j, k)if (i & (1 << j))cnt++;
		cs[i].resize(cnt + 1);
		vector<int> ids;
		rep(j, k)if (i & (1 << j))ids.push_back(j);
		rep1(j, cnt) {
			vector<int> v(cnt, -1);
			rep(k, j)v[k] = k;
			sort(all(v));
			do{
				vector<int> nex(j);
				rep(k, cnt)if (v[k] >= 0) {
					nex[v[k]] = ids[k];
				}
				cs[i][j].push_back(nex);
			} while (next_permutation(all(v)));
		}
	}
	vector<int> cnts(1 << k);
	rep(i, (1 << k))rep(j, k)if (i & (1 << j))cnts[i]++;
	int ans = 0;
	rep(i, n) {
		vector<bool> used(n);
		vector<int> nex;
		int s = (1 << k) - 1;
		function<bool()>dfs = [&]()->bool {
			if (nex.empty())return true;
			int sz = nex.size();
			for (auto& v : cs[s][sz]) {
				int ns = s;
				vector<int> nexs;
				rep(j, v.size()) {
					ns ^= (1 << v[j]);
					for (int pid : pres[v[j]][nex[j]]) {
						if (!used[pid]) {
							used[pid] = true;
							nexs.push_back(pid);
						}
					}
				}
				vector<int> cop = nexs;
				if (nexs.size() <= cnts[ns]) {
					swap(nex, nexs);
					swap(s, ns);
					if (dfs())return true;
					swap(nex, nexs);
					swap(s, ns);
				}
				for (int id : cop)used[id] = false;
			}
			return false;
		};
		nex.push_back(i);
		if (dfs())ans++;
	}
	cout << ans << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i, t)
	solve();
	return 0;
}