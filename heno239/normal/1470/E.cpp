#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
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

template<typename T>
struct SegT {
private:
	int sz; vector<T> node;
	T init_c;
	function<T(T, T)> f;
public:
	SegT(vector<T> v, T _init_c, function<T(T, T)> _f) {
		init_c = _init_c; f = _f;
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	SegT(int n, T _init_c, function<T(T, T)> _f) {
		init_c = _init_c; f = _f;
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	void update(int k, T a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};


ll num[30005][5];
void init(int c, int n) {
	rep(i, n + 1)rep(j, c + 1)num[i][j] = 0;
	rep(j, c + 1)num[0][j] = 1;
	rep1(i, n) {
		rep(j, 5) {
			rep(k, j + 1) {
				if (i - (k + 1) >= 0) {
					num[i][j] += num[i - (k + 1)][j - k];
				}
			}
		}
	}
}
void solve() {
	int n, c, q; cin >> n >> c >> q;
	init(c, n);
	vector<int> p(n);
	rep(i, n) {
		cin >> p[i]; p[i]--;
	}
	vector<vector<ll>> ad(c+1, vector<ll>(n));
	vector<vector<ll>> rad(c + 1, vector<ll>(n + 1));
	rep(i, n) {
		rep(k, c + 1) {
			vector<LP> vs;
			rep(j, k + 1) {
				if (i + j < n) {
					vs.push_back({ p[i + j],num[n - i - (j + 1)][k - j] });
				}
			}
			sort(all(vs));
			rep(j, vs.size()) {
				if (vs[j].first == p[i])break;
				ad[k][i] += vs[j].second;
				ad[k][i] = min(ad[k][i], INF);
			}
			rad[k][i + 1] = rad[k][i] + ad[k][i];
			rad[k][i + 1] = min(rad[k][i + 1], INF);
		}
	}
	//cout << ad[4][0] << "\n";
	auto query = [&](ll k, int i) {
		if (num[n][c] <= k)return -2;
		int loc = 0;
		int rc = c;
		while (true) {
			int l = loc-1;
			int r = n;
			while (r - l > 1) {
				int m = (l + r) / 2;
				ll cl = rad[rc][m + 1] - rad[rc][loc];
				ll cr = cl + num[n - m - 1][rc];
				//cout << k <<" "<<m<< " " << cl << " " << cr << "\n";
				if (cl <= k && k < cr) {
					l = m;
				}
				else {
					r = m;
				}
			}
			//cout << "? " << loc<<" "<<r << "\n";
			k -= rad[rc][r] - rad[rc][loc];
			loc = r;
			if (i < loc) {
				return p[i];
			}
			vector<pair<int,LP>> vs;
			rep(j, rc+1) {
				if (loc + j < n) {
					vs.push_back({ p[loc + j],{j,num[n - loc - j - 1][rc - j]} });
				}
			}
			//cout << loc << " babde " <<k<<" "<<vs.size()<< "\n";
			sort(all(vs));
			rep(j, vs.size()) {
				//cout << k << " " << vs[j].second.second << "\n";
				if (vs[j].second.second <= k) {
					k -= vs[j].second.second;
				}
				else {
					int len = vs[j].second.first;
					//cout << "??? " << len << "\n";
					if (loc + len >= i) {
						return p[loc + len - (i - loc)];
					}
					loc += len + 1;
					rc -= vs[j].second.first;
					break;
				}
			}
		}
	};
	rep(aa, q) {
		int i; ll j; cin >> i >> j; i--;j--;
		int ans = query(j, i);
		//cout << "ans is ";
		cout << ans+1 << "\n";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	int t; cin >> t; rep(i, t)
		solve();
	return 0;
}